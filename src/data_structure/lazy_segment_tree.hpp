#pragma once

template <class Lazy> struct lazy_segment_tree {
   public:
    using S = typename Lazy::value_type_S;
    using F = typename Lazy::value_type_F;
    lazy_segment_tree(int n) : lazy_segment_tree(std::vector<S>(n, Lazy::e())) {}
    lazy_segment_tree(const std::vector<S>& v) : _n((int)v.size()) {
        log = 0;
        while ((1U << log) < (unsigned int)(_n)) log++;
        size = 1 << log;
        d = std::vector<S>(2 * size, Lazy::e());
        lz = std::vector<F>(size, Lazy::id());
        for (int i = 0; i < _n; i++) d[i + size] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, const S& x) {
        assert(0 <= p and p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);  // 上から下へ伝搬
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);  // 下から上に更新
    }

    void chset(int p, const S& x) {
        assert(0 <= p and p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);  // 上から下へ伝搬
        d[p] = Lazy::op(d[p], x);
        for (int i = 1; i <= log; i++) update(p >> i);  // 下から上に更新
    }

    S operator[](int p) const {
        assert(0 <= p and p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);  // 上から下へ伝搬
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= _n);
        if (l == r) return Lazy::e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = Lazy::e(), smr = Lazy::e();
        while (l < r) {
            if (l & 1) sml = Lazy::op(sml, d[l++]);
            if (r & 1) smr = Lazy::op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return Lazy::op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, const F& f) {
        assert(0 <= p and p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = Lazy::mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    void apply(int l, int r, const F& f) {
        assert(0 <= l and l <= r and r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <class G> int max_right(int l, G& g) {
        assert(0 <= l && l <= _n);
        assert(g(Lazy::e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = Lazy::e();
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!g(Lazy::op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l <<= 1;
                    if (g(Lazy::op(sm, d[l]))) {
                        sm = Lazy::op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = Lazy::op(sm, d[l]);
            l++;
        } while ((l & -l) != l);  // 2べきまたは0のときfalse
        return _n;
    }

    template <class G> int min_left(int r, G& g) {
        assert(0 <= r && r <= _n);
        assert(g(Lazy::e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = Lazy::e();
        do {
            r--;
            while (r > 1 && (r & 1)) r >>= 1;
            if (!g(Lazy::op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (r << 1) | 1;
                    if (g(Lazy::op(d[r], sm))) {
                        sm = Lazy::op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = Lazy::op(d[r], sm);
        } while ((r & -r) != r);  // 2べきまたは0のときfalse
        return 0;
    }

   private:
    int _n, log, size;
    std::vector<S> d;
    std::vector<F> lz;
    inline void update(int k) { d[k] = Lazy::op(d[k << 1], d[(k << 1) | 1]); }
    void all_apply(int k, const F& f) {
        d[k] = Lazy::mapping(f, d[k]);
        if (k < size) lz[k] = Lazy::composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(k << 1, lz[k]);
        all_apply((k << 1) | 1, lz[k]);
        lz[k] = Lazy::id();
    }
};

/**
 * @brief Lazy Segment Tree (遅延セグメント木)
 * @docs docs/data_structure/lazy_segment_tree.md
 */
