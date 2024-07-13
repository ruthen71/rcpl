#pragma once

template <class T> struct CumulativeSum2D {
    int h, w;
    std::vector<std::vector<T>> seg;

    CumulativeSum2D() = default;

    CumulativeSum2D(int h, int w) : h(h), w(w), seg(h + 1, std::vector<T>(w + 1, T(0))) {}

    CumulativeSum2D(std::vector<std::vector<T>>& a) {
        h = (int)a.size();
        assert(h > 0);
        w = (int)a[0].size();
        seg.assign(h + 1, std::vector<T>(w + 1, T(0)));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                seg[i + 1][j + 1] = a[i][j];
            }
        }
        for (int i = 0; i < h + 1; i++) {
            for (int j = 0; j < w; j++) {
                seg[i][j + 1] += seg[i][j];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w + 1; j++) {
                seg[i + 1][j] += seg[i][j];
            }
        }
    }

    // [lx, rx) x [ly, ry)
    T sum(int lx, int ly, int rx, int ry) {
        assert(0 <= lx and lx <= rx and rx <= h);
        assert(0 <= ly and ly <= ry and ry <= w);
        return (seg[rx][ry] - seg[lx][ry] - seg[rx][ly] + seg[lx][ly]);
    }

    // (i, j) \in [lx, rx) x [ly, ry) seg[i][j] += z;
    void imos(int lx, int ly, int rx, int ry, T z = T(1)) {
        assert(0 <= lx and lx <= rx and rx <= h);
        assert(0 <= ly and ly <= ry and ry <= w);
        seg[lx][ly] += z;
        seg[lx][ry] -= z;
        seg[rx][ly] -= z;
        seg[rx][ry] += z;
    }

    void build() {
        for (int i = 0; i < h + 1; i++) {
            for (int j = 0; j < w; j++) {
                seg[i][j + 1] += seg[i][j];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w + 1; j++) {
                seg[i + 1][j] += seg[i][j];
            }
        }
    }

    // return A[x][y]
    T get(int x, int y) const {
        assert(0 <= x and x < h and 0 <= y and y < w);
        return seg[x][y];
    }

    std::vector<std::vector<T>> make_vector() { return seg; }
};