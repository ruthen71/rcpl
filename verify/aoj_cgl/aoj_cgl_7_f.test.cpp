#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F"
#define ERROR 0.00001

#include <bits/stdc++.h>

#include "geometry/tangent_point_cp.hpp"

int main() {
    Point<double> P;
    Circle<double> C;
    std::cin >> P >> C;
    auto [p, q] = tangent_point_cp(C, P);
    if (!compare_x(p, q)) std::swap(p, q);
    std::cout << std::fixed << std::setprecision(15) << p.x << ' ' << p.y << '\n';
    std::cout << std::fixed << std::setprecision(15) << q.x << ' ' << q.y << '\n';
    return 0;
}