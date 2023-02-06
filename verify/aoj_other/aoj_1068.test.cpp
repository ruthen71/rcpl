#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068"

#include <bits/stdc++.h>

#include "algebra/monoid_min.hpp"
#include "data_structure/segment_tree_2d.hpp"

void solve(int R, int C, int Q) {
    std::vector<std::vector<int>> A(R, std::vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            std::cin >> A[i][j];
        }
    }
    SegmentTree2D<MonoidMin<int>> seg(A);
    while (Q--) {
        int r1, c1, r2, c2;
        std::cin >> r1 >> c1 >> r2 >> c2;
        std::cout << seg.prod(r1, c1, r2 + 1, c2 + 1) << '\n';
    }
    return;
}

int main() {
    int R, C, Q;
    while (std::cin >> R >> C >> Q, !(R == 0 and C == 0 and Q == 0)) solve(R, C, Q);
    return 0;
}