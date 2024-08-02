#define PROBLEM "https://atcoder.jp/contests/abc022/tasks/abc022_d"
#define ERROR 0.0000001

#include <iostream>
#include <iomanip>

#include "geometry/farthest_pair.hpp"
#include "geometry/closest_pair.hpp"

int main() {
    int N;
    std::cin >> N;
    std::vector<Point<double>> A(N), B(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < N; i++) std::cin >> B[i];
    double ans1, ans2;
    {
        auto [ia, ja, da] = farthest_pair(A);
        auto [ib, jb, db] = farthest_pair(B);
        ans1 = db / da;
    }
    {
        auto [ia, ja, da] = closest_pair(A);
        auto [ib, jb, db] = closest_pair(B);
        ans2 = db / da;
    }
    assert(equal(ans1, ans2));
    std::cout << std::fixed << std::setprecision(15) << ans1 << '\n';
    return 0;
}