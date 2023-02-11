#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#include <bits/stdc++.h>

#include "geometry/is_orthogonal.hpp"
#include "geometry/is_parallel.hpp"

int main() {
    int Q;
    std::cin >> Q;
    while (Q--) {
        Line L1, L2;
        std::cin >> L1 >> L2;
        if (is_parallel(L1, L2)) {
            std::cout << 2 << '\n';
        } else if (is_orthogonal(L1, L2)) {
            std::cout << 1 << '\n';
        } else {
            std::cout << 0 << '\n';
        }
    }
    return 0;
}