#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B"
#define ERROR 0.000001

#include <bits/stdc++.h>

#include "geometry/incircle.hpp"

int main() {
    Point<double> a, b, c;
    std::cin >> a >> b >> c;
    auto cir = incircle(a, b, c);
    std::cout << std::fixed << std::setprecision(15) << cir.o.x << ' ' << cir.o.y << ' ' << cir.r << '\n';
    return 0;
}