#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <bits/stdc++.h>

#include "geometry/point.hpp"

int main() {
    using Pt = Point<long long>;
    std::vector<Pt> p = {{1, 0}, {2, 0}, {1, 1}, {2, 2}, {0, 1}, {0, 2}, {-1, 1}, {-2, 2}, {-1, 0}, {-2, 0}, {-1, -1}, {-2, -2}, {0, -1}, {0, -2}, {1, -1}, {2, -2}};
    for (int i = 0; i < 16; i++) {
        for (int j = i + 1; j < 16; j++) {
            assert(compare_arg(p[i], p[j]));
        }
    }
    long long a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}