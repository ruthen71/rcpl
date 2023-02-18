#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR 0.000001

#include <bits/stdc++.h>

#include "geometry/convex_polygon_diameter.hpp"

int main() {
    int N;
    std::cin >> N;
    Polygon P(N);
    std::cin >> P;
    auto [i, j, d] = convex_polygon_diameter(P);
    std::cout << std::fixed << std::setprecision(15) << d << '\n';
    return 0;
}