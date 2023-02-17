#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"

#include <bits/stdc++.h>

#include "geometry/contain.hpp"

int main() {
    int N;
    std::cin >> N;
    Polygon P(N);
    std::cin >> P;
    int Q;
    std::cin >> Q;
    while (Q--) {
        Point p;
        std::cin >> p;
        std::cout << contain(P, p) << '\n';
    }
    return 0;
}