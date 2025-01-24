#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include <iostream>

#include "dp/inversion_number.hpp"

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    std::cout << inversion_number<int>(A) << '\n';
    return 0;
}
