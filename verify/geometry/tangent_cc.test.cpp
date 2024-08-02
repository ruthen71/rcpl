#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>
#include <algorithm>

#include "geometry/tangent.hpp"

int main() {
    Circle<double> C1, C2;
    std::cin >> C1 >> C2;
    auto lines = tangent(C1, C2);
    std::vector<Point<double>> ans;
    for (auto&& l : lines) {
        if (is_intersect(C1, l.a)) {
            ans.push_back(l.a);
        }
        if (is_intersect(C1, l.b)) {
            ans.push_back(l.b);
        }
    }
    std::sort(ans.begin(), ans.end(), compare_x<double>);
    for (auto&& p : ans) {
        std::cout << std::fixed << std::setprecision(15) << p.x << ' ' << p.y << '\n';
    }
    return 0;
}