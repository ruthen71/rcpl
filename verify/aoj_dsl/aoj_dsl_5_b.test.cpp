#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include <bits/stdc++.h>

#include "data_structure/cumulative_sum_2d.hpp"

int main() {
    int N;
    std::cin >> N;
    int M = 1000;
    CumulativeSum2D<int> rui(M + 1, M + 1);
    while (N--) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        rui.imos(x1, y1, x2, y2);
    }
    rui.build();
    int ans = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++) ans = max(ans, rui(i, j));
    std::cout << ans << '\n';
    return 0;
}