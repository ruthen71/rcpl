#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"

#include <bits/stdc++.h>

#include "geometry/projection.hpp"

int main() {
    Line L;
    std::cin >> L;
    int Q;
    std::cin >> Q;
    while (Q--) {
        Point P;
        std::cin >> P;
        auto ans = projection(L, P);
        std::cout << ans << '\n';
    }
    return 0;
}