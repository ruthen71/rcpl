#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G"

#include <bits/stdc++.h>

#include "dp/knapsack_limitations.hpp"

int main() {
    int N, W;
    std::cin >> N >> W;
    std::vector<int> v(N), w(N), m(N);
    for (int i = 0; i < N; i++) std::cin >> v[i] >> w[i] >> m[i];
    auto ret1 = knapsack_limitations(w, v, m, W, -1);
    auto ans1 = *std::max_element(ret1.begin(), ret1.end());
    for (int i = 0; i < N; i++) v[i] = -v[i];
    auto ret2 = knapsack_limitations(w, v, m, W, 1, std::less<int>());
    auto ans2 = *std::min_element(ret2.begin(), ret2.end());
    assert(ans1 == -ans2);
    std::cout << ans1 << '\n';
    return 0;
}