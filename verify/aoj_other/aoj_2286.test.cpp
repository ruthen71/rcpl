#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2286"

#include <bits/stdc++.h>

#include "src/data_structure/cumulative_sum.hpp"
#include "src/math/totient_table.hpp"

int main() {
    auto ttt = totient_table(1000000);
    cumulative_sum<long long> rui(1000001);
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