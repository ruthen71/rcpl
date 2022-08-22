#pragma once

template <class T> struct cumulative_sum_2d {
    std::vector<std::vector<T>> cum;
    int H, W;

    cumulative_sum_2d(int W, int H) : H(H), W(W), cum(W + 1, std::vector<T>(H + 1, 0)) {}

    cumulative_sum_2d(std::vector<std::vector<T>> &A) {
        H = (int)A.size(), W = (int)A[0].size();
        cum.assign(H + 1, std::vector<T>(W + 1, 0));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cum[i + 1][j + 1] = A[i][j];
            }
        }
        for (int i = 0; i < H + 1; i++) {
            for (int j = 0; j < W; j++) {
                cum[i][j + 1] += cum[i][j];
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W + 1; j) {
                cum[i + 1][j] += cum[i][j];
            }
        }
    }

    // [lx, ly) x [rx, ry)
    T query(int lx, int ly, int rx, int ry) { return (cum[rx][ry] - cum[lx][ry] - cum[rx][ly] + cum[lx][ly]); }

    // A[x][y] = z
    void set(int x, int y, T z) { cum[x + 1][y + 1] = z; }

    // A[x][y] += z
    void add(int x, int y, T z) { cum[x + 1][y + 1] += z; }

    // (i, j) \in [lx, ly) x [rx, ry) cum[i][j] += z;
    void imos(int lx, int ly, int rx, int ry, T z = 1) {
        add(lx, ly, z);
        add(lx, ry, -z);
        add(rx, ly, -z);
        add(rx, ry, z);
    }

    void build() {
        for (int i = 0; i < H + 1; i++) {
            for (int j = 0; j < W; j++) {
                cum[i][j + 1] += cum[i][j];
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W + 1; j++) {
                cum[i + 1][j] += cum[i][j];
            }
        }
    }

    T get(int x, int y) { return cum[x + 1][y + 1]; }

    // output
    friend ostream &operator<<(ostream &os, const cumulative_sum_2d &A) {
        for (int i = 0; i < (int)A.size(); i++) {
            for (int j = 0; j < (int)A[i].size(); j++) {
                os << A[i][j] << " \n"[j == (int)A[i].size() - 1];
            }
        }
        return os;
    }
};

/**
 * @brief 2次元累積和
 * @docs docs/data_structure/cumulative_sum_2d.md
 */
