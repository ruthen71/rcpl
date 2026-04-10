#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <iostream>

#include "../../algebra/monoid/monoid_or.hpp"
#include "../../segment_tree/segment_tree.hpp"

void test1_basic() {
    assert(MonoidOr<int>::commutative == true);
    assert(MonoidOr<int>::identity() == 0);
}

void test2_sequence() {
    std::vector<int> a = {3, 1, 4, 1, 5};
    SegmentTree<MonoidOr<int>> seg(a);
    assert(seg.prod(0, 0) == 0);
    assert(seg.prod(0, 2) == (a[0] | a[1]));
    assert(seg.prod(1, 3) == (a[1] | a[2]));
    assert(seg.prod(2, 4) == (a[2] | a[3]));
    assert(seg.prod(3, 5) == (a[3] | a[4]));
    assert(seg.prod(0, 5) == (a[0] | a[1] | a[2] | a[3] | a[4]));
}

int main() {
    test1_basic();
    test2_sequence();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
