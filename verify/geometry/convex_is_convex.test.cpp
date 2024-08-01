#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"

#include <iostream>

#include "geometry/polygon.hpp"

int main() {
    int N;
    std::cin >> N;
    Polygon<long long> P(N);
    std::cin >> P;
    bool ans = polygon_is_convex(P);
    std::reverse(P.begin(), P.end());
    assert(ans == polygon_is_convex(P));
    std::cout << ans << '\n';
    return 0;
}