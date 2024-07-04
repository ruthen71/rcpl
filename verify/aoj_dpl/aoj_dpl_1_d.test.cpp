#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include <iostream>
#include <vector>

#include "dp/longest_increasing_subsequence.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::cout << longest_increasing_subsequence(a) << '\n';
    return 0;
}