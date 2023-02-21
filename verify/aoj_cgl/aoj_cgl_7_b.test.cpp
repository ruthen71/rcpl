#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B"
#define ERROR 0.000001

#include <bits/stdc++.h>

#include "geometry/incircle.hpp"

int main() {
    Point a, b, c;
    std::cin >> a >> b >> c;
    auto [p, r] = incircle(a, b, c);
    std::cout << p << ' ' << r << '\n';
    return 0;
}