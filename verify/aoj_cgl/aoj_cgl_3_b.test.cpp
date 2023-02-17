#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"

#include <bits/stdc++.h>

#include "geometry/is_convex.hpp"

int main() {
    int N;
    std::cin >> N;
    Polygon P(N);
    std::cin >> P;
    bool ans = is_convex(P);
    std::reverse(P.begin(), P.end());
    assert(ans == is_convex(P));
    std::cout << ans << '\n';
    return 0;
}