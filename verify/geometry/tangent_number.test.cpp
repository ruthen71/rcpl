#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A"

#include <iostream>

#include "geometry/circle.hpp"

int main() {
    Circle<long long> C1, C2;
    std::cin >> C1 >> C2;
    std::cout << tangent_number(C1, C2) << '\n';
    return 0;
}