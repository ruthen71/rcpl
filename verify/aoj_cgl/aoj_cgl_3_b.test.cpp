#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"

#include <bits/stdc++.h>

#include "geometry/polygon_is_convex.hpp"

int main() {
    int N;
    std::cin >> N;
    Polygon<double> P(N);
    std::cin >> P;
    bool ans = polygon_is_convex(P);
    std::reverse(P.begin(), P.end());
    assert(ans == polygon_is_convex(P));
    std::cout << ans << '\n';
    return 0;
}