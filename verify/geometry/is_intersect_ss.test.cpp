#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"

#include <iostream>

#include "geometry/is_intersect.hpp"

int main() {
    int Q;
    std::cin >> Q;
    while (Q--) {
        Segment<long long> S1, S2;
        std::cin >> S1 >> S2;
        std::cout << is_intersect(S1, S2) << '\n';
    }
    return 0;
}