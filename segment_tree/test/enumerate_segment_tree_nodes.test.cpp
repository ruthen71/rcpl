#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <iostream>

#include "../../segment_tree/enumerate_segment_tree_nodes.hpp"

std::vector<std::pair<long long, long long>> solve(long long l, long long r) {
    const long long n2 = 1LL << 60;
    auto res = enumerate_segment_tree_range_covering_nodes(n2, l, r);
    std::vector<std::pair<long long, long long>> ans;
    for (auto&& i : res) {
        ans.push_back(segment_tree_node_to_range(n2, i));
    }
    return ans;
}

void test1_sample1() {
    long long l = 3, r = 19;
    std::vector<std::pair<long long, long long>> sol = {
        {3, 4}, {4, 8}, {8, 16}, {16, 18}, {18, 19}};
    assert(solve(l, r) == sol);
}
void test2_sample2() {
    long long l = 0, r = 1024;
    std::vector<std::pair<long long, long long>> sol = {{0, 1024}};
    assert(solve(l, r) == sol);
}
void test3_sample3() {
    long long l = 3940649673945088, r = 11549545024454656;
    std::vector<std::pair<long long, long long>> sol = {
        {3940649673945088, 3940649673949184},
        {3940649673949184, 4503599627370496},
        {4503599627370496, 9007199254740992},
        {9007199254740992, 11258999068426240},
        {11258999068426240, 11540474045136896},
        {11540474045136896, 11549270138159104},
        {11549270138159104, 11549545016066048},
        {11549545016066048, 11549545024454656}};
    assert(solve(l, r) == sol);
}

int main() {
    // https://atcoder.jp/contests/abc349/tasks/abc349_d
    test1_sample1();
    test2_sample2();
    test3_sample3();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
