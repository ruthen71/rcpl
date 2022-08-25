#pragma once

template <class Monoid> struct segment_tree_2d {
   public:
    using S = typename Monoid::value_type;
    segment_tree_2d() : segment_tree_2d(0, 0) {}
    segment_tree_2d(int h, int w) : segment_tree_2d(std::vector<std::vector<S>>(h, std::vector<S>(w, Monoid::e()))) {}
    segment_tree_2d(const std::vector<std::vector<S>>& v) : _h((int)v.size()), _w((int)v[0].size()) {
        logh = 0;
        while ((1U << logh) < (unsigned int)(_h)) logh++;
        sizeh = 1 << logh;
        logw = 0;
        while ((1U << logw) < (unsigned int)(_w)) logw++;
        sizew = 1 << logw;
        d = std::vector<std::vector<S>>(2 * sizeh, std::vector<S>(2 * sizew, Monoid::e()));
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) {
                d[i + sizeh][j + sizew] = v[i][j];
            }
        }
        for (int i = sizeh - 1; i >= 1; i--) {
            for (int j = sizew; j < 2 * sizew; j++) {
                update_bottom(i, j);
            }
        }
        for (int i = 0; i < 2 * sizeh; i++) {
            for (int j = sizew - 1; j >= 1; j--) {
                update_else(i, j);
            }
        }
    }

    void set(int h, int w, const S& x) {
        assert(0 <= h and h < _h and 0 <= w and w < _w);
        h += sizeh;
        w += sizew;
        d[h][w] = x;
        for (int i = 1; i <= logh; i++) update_bottom(h >> i, w);
        for (int i = 0; i <= logh; i++) {
            for (int j = 1; j <= logw; j++) {
                update_else(h >> i, w >> j);
            }
        }
    }

    void chset(int h, int w, const S& x) {
        assert(0 <= h and h < _h and 0 <= w and w < _w);
        h += sizeh;
        w += sizew;
        d[h][w] = Monoid::op(d[h][w], x);
        for (int i = 1; i <= logh; i++) update_bottom(h >> i, w);
        for (int i = 0; i <= logh; i++) {
            for (int j = 1; j <= logw; j++) {
                update_else(h >> i, w >> j);
            }
        }
    }

    S operator()(int h, int w) const {
        assert(0 <= h and h < _h and 0 <= w and w < _w);
        return d[h + sizeh][w + sizew];
    }

    S inner_prod(int h, int w1, int w2) {
        S sml = Monoid::e(), smr = Monoid::e();
        while (w1 < w2) {
            if (w1 & 1) sml = Monoid::op(sml, d[h][w1++]);
            if (w2 & 1) smr = Monoid::op(d[h][--w2], smr);
            w1 >>= 1;
            w2 >>= 1;
        }
        return Monoid::op(sml, smr);
    }

    S prod(int h1, int w1, int h2, int w2) {
        assert(0 <= h1 and h1 <= h2 and h2 <= _h);
        assert(0 <= w1 and w1 <= w2 and w2 <= _w);
        S sml = Monoid::e(), smr = Monoid::e();
        h1 += sizeh;
        h2 += sizeh;
        w1 += sizew;
        w2 += sizew;

        while (h1 < h2) {
            if (h1 & 1) sml = Monoid::op(sml, inner_prod(h1++, w1, w2));
            if (h2 & 1) smr = Monoid::op(inner_prod(--h2, w1, w2), smr);
            h1 >>= 1;
            h2 >>= 1;
        }
        return Monoid::op(sml, smr);
    }

    S all_prod() const { return d[1][1]; }

   private:
    int _h, logh, sizeh, _w, logw, sizew;
    std::vector<std::vector<S>> d;
    inline void update_bottom(int i, int j) { d[i][j] = Monoid::op(d[(i << 1) | 0][j], d[(i << 1) | 1][j]); }
    inline void update_else(int i, int j) { d[i][j] = Monoid::op(d[i][(j << 1) | 0], d[i][(j << 1) | 1]); }
};

/**
 * @brief 2D Segment Tree (2次元セグメント木)
 * @docs docs/data_structure/segment_tree_2d.md
 */
