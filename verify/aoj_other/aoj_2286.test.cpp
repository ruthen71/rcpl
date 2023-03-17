#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2286"

#include <bits/stdc++.h>

#include "data_structure/cumulative_sum.hpp"
#include "math/totient_table.hpp"

int main() {
    auto ttt = totient_table(1000000);
    std::vector<long long> tl(ttt.size());
    for (int i = 0; i < (int)ttt.size(); i++) tl[i] = ttt[i];
    CumulativeSum<long long> rui(tl);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::cout << rui.sum(0, n + 1) + 1 << '\n';
    }
    return 0;
}