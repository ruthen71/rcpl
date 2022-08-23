#define PROBLEM "https://yukicoder.me/problems/no/1036"

#include <bits/stdc++.h>

#include "src/algebra/monoid_gcd.hpp"
#include "src/data_structure/segment_tree.hpp"

int main() {
    int N;
    std::cin >> N;
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    segment_tree<monoid_gcd<long long>> seg(A);
    auto f = [](long long v) -> bool { return v != 1; };
    long long ansL = 0, ansR = 0;
    for (int l = 0; l < N; l++) {
        int r = seg.max_right(l, f);
        ansL += N - r;
    }
    for (int r = N; r > 0; r--) {
        int l = seg.min_left(r, f);
        ansR += l;
    }
    assert(ansL == ansR);
    std::cout << ansL << '\n';
    return 0;
}