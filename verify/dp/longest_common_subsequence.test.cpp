#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include <iostream>
#include "dp/longest_common_subsequence.hpp"

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::string s, t;
        std::cin >> s >> t;
        std::cout << longest_common_subsequence(s, t).size() << '\n';
    }
    return 0;
}