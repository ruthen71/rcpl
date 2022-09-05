#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <bits/stdc++.h>

#include "src/math/totient.hpp"

int main() {
    long long n;
    std::cin >> n;
    std::cout << totient(n) << '\n';
    return 0;
}