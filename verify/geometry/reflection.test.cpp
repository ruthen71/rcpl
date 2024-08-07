#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR 0.00000001

#include <iostream>
#include <iomanip>

#include "geometry/line.hpp"

int main() {
    Line<double> L;
    int Q;
    std::cin >> L >> Q;
    while (Q--) {
        Point<double> P;
        std::cin >> P;
        auto ans = reflection(L, P);
        std::cout << std::fixed << std::setprecision(15) << ans.x << ' ' << ans.y << '\n';
    }
    return 0;
}