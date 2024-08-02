#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"
#define ERROR 0.00000001

#include <iostream>
#include <iomanip>

#include "geometry/distance.hpp"

int main() {
    int Q;
    std::cin >> Q;
    while (Q--) {
        Segment<double> S1, S2;
        std::cin >> S1 >> S2;
        auto d = distance(S1, S2);
        std::cout << std::fixed << std::setprecision(15) << d << '\n';
    }
    return 0;
}