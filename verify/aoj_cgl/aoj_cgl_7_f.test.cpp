#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F"
#define ERROR 0.00001

#include <bits/stdc++.h>

#include "geometry/tangent_point_cp.hpp"

int main() {
    Point P;
    Circle C;
    std::cin >> P >> C;
    auto [p, q] = tangent_point_cp(C, P);
    if (!compare_x(p, q)) std::swap(p, q);
    std::cout << p << '\n';
    std::cout << q << '\n';
    return 0;
}