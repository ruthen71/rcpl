#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>
#include <algorithm>

#include "geometry/tangent_point.hpp"

int main() {
    Point<double> P;
    Circle<double> C;
    std::cin >> P >> C;
    auto res = tangent_point(C, P);
    std::sort(res.begin(), res.end(), compare_x<double>);
    std::cout << std::fixed << std::setprecision(15) << res[0].x << ' ' << res[0].y << '\n';
    std::cout << std::fixed << std::setprecision(15) << res[1].x << ' ' << res[1].y << '\n';
    return 0;
}