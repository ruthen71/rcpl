#define PROBLEM "https://yukicoder.me/problems/no/186"

#include <bits/stdc++.h>
#include "math/chinese_remainder_theorem.hpp"

int main() {
    std::vector<i64> X(3), Y(3);
    for (int i = 0; i < 3; i++) std::cin >> X[i] >> Y[i];
    auto [r, m] = chinese_remainder_theorem(X, Y);
    if (m == 0) {
        std::cout << -1 << '\n';
    } else if (r == 0) {
        std::cout << m << '\n';
    } else {
        std::cout << r << '\n';
    }
    return 0;
}
