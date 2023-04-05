#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"

#include <bits/stdc++.h>

#include "geometry/polygon_contain.hpp"

int main() {
    int N;
    std::cin >> N;
    Polygon<double> P(N);
    std::cin >> P;
    int Q;
    std::cin >> Q;
    while (Q--) {
        Point<double> p;
        std::cin >> p;
        std::cout << polygon_contain(P, p) << '\n';
    }
    return 0;
}