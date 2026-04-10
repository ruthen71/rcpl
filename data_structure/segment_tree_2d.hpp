#pragma once

#include "../misc/bit_ceil.hpp"
#include "../misc/countr_zero.hpp"

#include <cassert>
#include <vector>

// Segment Tree 2D
template <class MS> struct SegmentTree2D {
  public:
    using S = typename MS::value_type;

    SegmentTree2D() = default;

    explicit SegmentTree2D(int h, int w)
        : SegmentTree2D(std::vector(h, std::vector<S>(w, MS::identity()))) {}

    explicit SegmentTree2D(const std::vector<std::vector<S>>& v)
        : h((int)(v.size())), w((int)(v[0].size())) {
        sizeh = bit_ceil(h);
        logh = countr_zero(sizeh);
        sizew = bit_ceil(w);
        logw = countr_zero(sizew);
        d = std::vector(sizeh << 1, std::vector<S>(sizew << 1, MS::identity()));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                d[i + sizeh][j + sizew] = v[i][j];
            }
        }
        for (int i = sizeh - 1; i >= 1; i--) {
            for (int j = sizew; j < (sizew << 1); j++) {
                update_bottom(i, j);
            }
        }
        for (int i = 0; i < (sizeh << 1); i++) {
            for (int j = sizew - 1; j >= 1; j--) {
                update_else(i, j);
            }
        }
    }

    void set(int h, int w, const S& x) {
        assert(0 <= h and h < h and 0 <= w and w < w);
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
        assert(0 <= h and h < h and 0 <= w and w < w);
        h += sizeh;
        w += sizew;
        d[h][w] = MS::operation(d[h][w], x);
        for (int i = 1; i <= logh; i++) update_bottom(h >> i, w);
        for (int i = 0; i <= logh; i++) {
            for (int j = 1; j <= logw; j++) {
                update_else(h >> i, w >> j);
            }
        }
    }

    S operator()(int h, int w) const {
        assert(0 <= h and h < h and 0 <= w and w < w);
        return d[h + sizeh][w + sizew];
    }

    S get(int h, int w) const {
        assert(0 <= h and h < h and 0 <= w and w < w);
        return d[h + sizeh][w + sizew];
    }

    S inner_prod(int h, int w1, int w2) {
        S sml = MS::identity(), smr = MS::identity();
        while (w1 < w2) {
            if (w1 & 1) sml = MS::operation(sml, d[h][w1++]);
            if (w2 & 1) smr = MS::operation(d[h][--w2], smr);
            w1 >>= 1;
            w2 >>= 1;
        }
        return MS::operation(sml, smr);
    }

    S prod(int h1, int w1, int h2, int w2) {
        assert(0 <= h1 and h1 <= h2 and h2 <= h);
        assert(0 <= w1 and w1 <= w2 and w2 <= w);
        S sml = MS::identity(), smr = MS::identity();
        h1 += sizeh;
        h2 += sizeh;
        w1 += sizew;
        w2 += sizew;

        while (h1 < h2) {
            if (h1 & 1) sml = MS::operation(sml, inner_prod(h1++, w1, w2));
            if (h2 & 1) smr = MS::operation(inner_prod(--h2, w1, w2), smr);
            h1 >>= 1;
            h2 >>= 1;
        }
        return MS::operation(sml, smr);
    }

    S all_prod() const { return d[1][1]; }

    std::vector<std::vector<S>> make_vector() {
        std::vector vec(h, std::vector<S>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) vec[i][j] = get(i, j);
        }
        return vec;
    }

  private:
    int h, logh, sizeh, w, logw, sizew;
    std::vector<std::vector<S>> d;

    inline void update_bottom(int i, int j) {
        d[i][j] = MS::operation(d[(i << 1) | 0][j], d[(i << 1) | 1][j]);
    }

    inline void update_else(int i, int j) {
        d[i][j] = MS::operation(d[i][(j << 1) | 0], d[i][(j << 1) | 1]);
    }
};
