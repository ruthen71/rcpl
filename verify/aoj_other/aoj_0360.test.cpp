#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0360"

#include <bits/stdc++.h>

#include "data_structure/cumulative_sum.hpp"

int main() {
    int a, b, N;
    std::cin >> a >> b >> N;
    CumulativeSum<int> rui(1000);
    for (int i = 0; i < N; i++) {
        int s, f;
        std::cin >> s >> f;
        rui.imos(s, f);
    }
    rui.build();
    bool ok = false;
    for (int i = a; i < b; i++) {
        if (rui.get(i)) ok = true;
    }
    std::cout << ok << '\n';
    return 0;
}