#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>
#include <algorithm>

#include "geometry/cross_point.hpp"

int main() {
    Circle<double> C1, C2;
    std::cin >> C1 >> C2;
    auto res = cross_point(C1, C2);
    std::sort(res.begin(), res.end());
    if (res.size() == 1) res.push_back(res[0]);
    std::cout << std::fixed << std::setprecision(15) << res[0].x << ' ' << res[0].y << ' ' << res[1].x << ' ' << res[1].y << '\n';
    return 0;
}