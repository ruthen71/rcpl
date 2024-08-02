#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>
#include <algorithm>

#include "geometry/tangent.hpp"

int main() {
    Point<double> P;
    Circle<double> C;
    std::cin >> P >> C;
    auto lines = tangent(C, P);
    std::vector<Point<double>> ans;
    for (auto&& l : lines) {
        if (is_intersect(C, l.a)) {
            ans.push_back(l.a);
        }
        if (is_intersect(C, l.b)) {
            ans.push_back(l.b);
        }
    }
    assert(ans.size() == 2);
    std::sort(ans.begin(), ans.end(), compare_x<double>);
    std::cout << std::fixed << std::setprecision(15) << ans[0].x << ' ' << ans[0].y << '\n';
    std::cout << std::fixed << std::setprecision(15) << ans[1].x << ' ' << ans[1].y << '\n';
    return 0;
}