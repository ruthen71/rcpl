#pragma once

template <class Monoid> struct segment_tree {
    using S = typename Monoid::value_type;
    int _n, log, size;
    std::vector<S> d;
    segment_tree() : segment_tree(0) {}
    segment_tree(int n) : segment_tree(std::vector<S>(n, Monoid::e())) {}
    segment_tree(const std::vector<S>& v) : _n((int)v.size()) {
        log = 0;
        while ((1U << log) < (unsigned int)(_n)) log++;
        size = 1 << log;
        d = std::vector<S>(2 * size, Monoid::e());
        for (int i = 0; i < _n; i++) d[i + size] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void update(int k) { d[k] = Monoid::op(d[k << 1], d[(k << 1) | 1]); }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S vl = Monoid::e(), vr = Monoid::e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) vl = Monoid::op(vl, d[l++]);
            if (r & 1) vr = Monoid::op(d[--r], vr);
            l >>= 1;
            r >>= 1;
        }
        return Monoid::op(vl, vr);
    }

    S all_prod() const { return d[1]; }

    template <class F> int max_right(int l, F& f) const {
        assert(0 <= l && l <= _n);
        assert(f(Monoid::e()));
        if (l == _n) return _n;
        l += size;
        S sm = Monoid::e();
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!f(Monoid::op(sm, d[l]))) {
                while (l < size) {
                    l <<= 1;
                    if (f(Monoid::op(sm, d[l]))) {
                        sm = Monoid::op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = Monoid::op(sm, d[l]);
            l++;
        } while ((l & -l) != l);  // 2べきまたは0のときfalse
        return _n;
    }

    template <class F> int min_left(int r, F& f) const {
        assert(0 <= r && r <= _n);
        assert(f(Monoid::e()));
        if (r == 0) return 0;
        r += size;
        S sm = Monoid::e();
        do {
            r--;
            while (r > 1 && (r & 1)) r >>= 1;
            if (!f(Monoid::op(d[r], sm))) {
                while (r < size) {
                    r = (r << 1) | 1;
                    if (f(Monoid::op(d[r], sm))) {
                        sm = Monoid::op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = Monoid::op(d[r], sm);
        } while ((r & -r) != r);  // 2べきまたは0のときfalse
        return 0;
    }
};

/**
 * @brief Segment Tree (セグメント木)
 * @docs docs/data_structure/segment_tree.md
 */
