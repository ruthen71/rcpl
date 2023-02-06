#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>

#include "string/rolling_hash.hpp"

int main() {
    std::string T, P;
    std::cin >> T >> P;
    rolling_hash<modint261> rh;
    auto rht = rh.build(T);
    auto rhp = rh.build(P);
    for (int i = 0; i + P.size() <= T.size(); i++) {
        if (rh.prod(rht, i, i + P.size()) == rh.prod(rhp, 0, P.size())) {
            std::cout << i << '\n';
        }
    }
    return 0;
}
