#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include <iostream>
#include <vector>
#include <algorithm>

#include "geometry/point.hpp"

int main() {
    assert(std::atan2(0LL, 0LL) == 0.0);
    assert(std::atan2(0.0, 0.0) == 0.0);
    assert(std::atan2(0.0L, 0.0L) == 0.0L);
    {
        // x < 0, y = 0 (270°) の半直線スタート, x < 0, y = 0 自体は最後に含める
        std::vector<Point<long long>> p = {
            {-1, -1}, {-2, -2},          // -3/4 PI
            {0, -1},  {0, -2},           // -2/4 PI
            {1, -1},  {2, -2},           // -1/4 PI
            {0, 0},   {1, 0},   {2, 0},  //  0/4 PI
            {1, 1},   {2, 2},            //  1/4 PI
            {0, 1},   {0, 2},            //  2/4 PI
            {-1, 1},  {-2, 2},           //  3/4 PI
            {-1, 0},  {-2, 0},           //  4/4 PI
        };
        const int n = (int)(p.size());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                assert((i < j) == compare_atan2(p[i], p[j]));
            }
        }
    }
    int N;
    std::cin >> N;
    std::vector<Point<long long>> P(N);
    for (int i = 0; i < N; i++) std::cin >> P[i];
    std::sort(P.begin(), P.end(), compare_atan2<long long>);
    for (int i = 0; i < N; i++) std::cout << P[i].x << " " << P[i].y << "\n";
    return 0;
}