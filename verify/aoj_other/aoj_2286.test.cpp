#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2286"

#include <bits/stdc++.h>

#include "data_structure/cumulative_sum.hpp"
#include "math/totient_table.hpp"

int main() {
    auto ttt = totient_table(1000000);
    CumulativeSum<long long> rui(1000001);
    for (int i = 0; i <= 1000000; i++) rui.add(i, ttt[i]);
    rui.build();
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::cout << rui.sum(0, n + 1) + 1 << '\n';
    }
    return 0;
}