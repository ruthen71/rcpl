#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"
#define ERROR 0.00000001

#include <bits/stdc++.h>

#include "geometry/projection.hpp"

int main() {
    Line<double> L;
    std::cin >> L;
    int Q;
    std::cin >> Q;
    while (Q--) {
        Point<double> P;
        std::cin >> P;
        auto ans = projection(L, P);
        std::cout << ans.x << ' ' << ans.y << '\n';
    }
    return 0;
}