#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3206"

#include <bits/stdc++.h>

#include "data_structure/dice.hpp"

void solve(int N) {
    std::vector<Dice> ds(N);
    for (int i = 0; i < N; i++) {
        std::vector<std::string> S(5);
        for (int j = 0; j < 5; j++) std::cin >> S[j];
        ds[i] = read_dice(S);
    }
    for (int i = 0; i < N; i++) {
        std::string ans;
        for (int j = 0; j < N; j++) {
            auto a = ds[i], b = ds[j];
            auto r = min_difference(a, b);
            ans += '0' + r;
        }
        std::cout << ans << '\n';
    }
    return;
}

int main() {
    int N;
    while (std::cin >> N, N != 0) solve(N);
    return 0;
}