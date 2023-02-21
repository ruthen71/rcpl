#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B"
#define ERROR 0.000001

#include <bits/stdc++.h>

#include "geometry/incircle.hpp"

int main() {
    Point a, b, c;
    std::cin >> a >> b >> c;
    auto cir = incircle(a, b, c);
    std::cout << cir.o << ' ' << cir.r << '\n';
    return 0;
}