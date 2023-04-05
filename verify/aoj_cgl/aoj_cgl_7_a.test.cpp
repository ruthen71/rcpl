#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A"

#include <bits/stdc++.h>

#include "geometry/tangent_number_cc.hpp"

int main() {
    Circle<double> C1, C2;
    std::cin >> C1 >> C2;
    std::cout << tangent_number_cc(C1, C2) << '\n';
    return 0;
}