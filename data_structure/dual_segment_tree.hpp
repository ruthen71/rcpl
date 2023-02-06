#pragma once

template <class Dual> struct dual_segment_tree {
   public:
    using F = typename Dual::value_type;
    dual_segment_tree(int n) : dual_segment_tree(std::vector<F>(n, Dual::id())) {}
    dual_segment_tree(const std::vector<F>& v) : _n((int)v.size()) {
        log = 0;
        while ((1U << log) < (unsigned int)(_n)) log++;
        size = 1 << log;
        lz = std::vector<F>(size << 1, Dual::id());
        for (int i = 0; i < _n; i++) lz[i + size] = v[i];
    }

    F operator[](int p) {
        assert(0 <= p and p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);  // 上から下へ伝搬
        return lz[p];
    }

    F get(int p) {
        assert(0 <= p and p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);  // 上から下へ伝搬
        return lz[p];
    }

    void set(int p, const F& x) {
        assert(0 <= p and p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);  // 上から下へ伝搬
        lz[p] = x;
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
    }

   private:
    int _n, log, size;
    std::vector<F> lz;
    void all_apply(int k, const F& f) { lz[k] = Dual::composition(f, lz[k]); }
    void push(int k) {
        all_apply(k << 1, lz[k]);
        all_apply((k << 1) | 1, lz[k]);
        lz[k] = Dual::id();
    }
};
