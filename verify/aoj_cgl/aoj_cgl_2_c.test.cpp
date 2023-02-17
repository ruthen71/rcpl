#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"
#define ERROR 0.00000001

#include <bits/stdc++.h>

#include "geometry/cross_point_ss.hpp"

int main() {
    int Q;
    std::cin >> Q;
    while (Q--) {
        Segment S1, S2;
        std::cin >> S1 >> S2;
        auto p = cross_point_ss(S1, S2);
        std::cout << p << '\n';
    }
    return 0;
}