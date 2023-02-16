#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"

#include <bits/stdc++.h>

#include "geometry/is_intersect_ss.hpp"

int main() {
    int Q;
    std::cin >> Q;
    while (Q--) {
        Segment S1, S2;
        std::cin >> S1 >> S2;
        std::cout << is_intersect_ss(S1, S2) << '\n';
    }
    return 0;
}