#define PROBLEM "https://atcoder.jp/contests/abc349/tasks/abc349_d"

#include <iostream>
#include "data_structure/enumerate_segment_tree_nodes.hpp"

int main() {
    long long L, R;
    std::cin >> L >> R;
    const long long N2 = 1LL << 60;
    auto res = enumerate_segment_tree_range_covering_nodes(N2, L, R);
    std::cout << res.size() << '\n';
    for (auto&& i : res) {
        auto [l, r] = segment_tree_node_to_range(N2, i);
        std::cout << l << ' ' << r << '\n';
    }
    return 0;
}