#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"

#include <bits/stdc++.h>

#include "geometry/polygon_area.hpp"

int main() {
    int N;
    std::cin >> N;
    Polygon<double> P(N);
    std::cin >> P;
    std::cout << std::fixed << std::setprecision(1) << polygon_area(P) << '\n';
    return 0;
}