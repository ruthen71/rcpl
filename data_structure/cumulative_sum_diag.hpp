#pragma once

template <class T, int delta = 1> struct CumulativeSumDiag {
    std::vector<std::vector<T>> cum;
    int H, W;

    CumulativeSumDiag(std::vector<std::vector<T>> &A) {
        assert(A.size() > 0);
        H = (int)A.size(), W = (int)A[0].size();
        cum.assign(H + W, std::vector<T>(W + 1, 0));
        if (delta == 1) {
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    cum[i + W - 1 - j][j + 1] = A[i][j];
                }
            }
            for (int i = 0; i < H + W; i++) {
                for (int j = 0; j < W; j++) {
                    cum[i][j + 1] += cum[i][j];
                }
            }
        } else {
            assert(delta == -1);
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    cum[i + j][j + 1] = A[i][j];
                }
            }
            for (int i = 0; i < H + W; i++) {
                for (int j = 0; j < W; j++) {
                    cum[i][j + 1] += cum[i][j];
                }
            }
        }
    }

    T sum(int x1, int y1, int x2, int y2) {
        assert(0 <= x1 and x1 < H and 0 <= y1 and y1 < W);
        assert(0 <= x2 and x2 < H and 0 <= y2 and y2 < W);
        assert(y1 <= y2);
        if (delta == 1) {
            // sum of (x1, y1), (x1 + 1, y1 + 1), ... , (x2, y2)
            assert(x1 - y1 == x2 - y2);
            return cum[x1 + W - 1 - y1][y2 + 1] - cum[x1 + W - 1 - y1][y1];
        } else {
            // sum of (x1, y1), (x1 - 1, y1 + 1), ... , (x2, y2)
            assert(x1 + y1 == x2 + y2);
            return cum[x1 + y1][y2 + 1] - cum[x1 + y1][y1];
        }
    }
};