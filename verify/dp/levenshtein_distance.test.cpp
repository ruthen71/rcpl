#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E"

#include <iostream>

#include "dp/levenshtein_distance.hpp"

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::cout << levenshtein_distance(s, t) << '\n';
    return 0;
}