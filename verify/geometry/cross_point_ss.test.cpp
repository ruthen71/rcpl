#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"
#define ERROR 0.00000001

#include <iostream>
#include <iomanip>

#include "geometry/cross_point.hpp"

int main() {
    int Q;
    std::cin >> Q;
    while (Q--) {
        Segment<double> S1, S2;
        std::cin >> S1 >> S2;
        auto p = cross_point(S1, S2);
        std::cout << std::fixed << std::setprecision(15) << p.x << ' ' << p.y << '\n';
    }
    return 0;
}