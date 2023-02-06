#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"

#include <bits/stdc++.h>

#include "dp/histogram_largest_rectangle.hpp"

int main() {
    int N;
    std::cin >> N;
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    std::cout << histogram_largest_rectangle(A) << '\n';
    return 0;
}