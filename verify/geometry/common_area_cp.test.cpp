#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H"

#include <iostream>
#include <iomanip>

#include "geometry/common_area.hpp"

int main() {
    int n;
    double r;
    std::cin >> n >> r;
    Polygon<double> p(n);
    std::cin >> p;
    // 適当に平行移動しておく
    Circle<double> c(Point<double>(100, 100), r);
    for (auto&& pt : p) pt.x += 100, pt.y += 100;
    std::cout << std::fixed << std::setprecision(15) << common_area(c, p) << '\n';
    return 0;
}