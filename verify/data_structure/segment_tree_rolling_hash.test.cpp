#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <iostream>

#include "../../algebra/monoid/monoid_rolling_hash.hpp"
#include "../../segment_tree/segment_tree.hpp"
#include "../../math/modint261.hpp"

using mint = mint261;
using mrh = MonoidRollingHash<mint>;
template <> mint mrh::base = 0;

void test1_basic() {
    assert(mrh::commutative == false);
    assert(mrh::identity().hash == mint(0));
    assert(mrh::identity().power == mint(1));
}

void test2_sequence() {
    mint B = mrh::base;

    std::vector<Hash<mint>> a = {
        mrh::make_element(mint(3)),
        mrh::make_element(mint(1)),
        mrh::make_element(mint(4)),
    };
    SegmentTree<mrh> seg(a);

    assert(seg.prod(0, 0).hash == mint(0));
    assert(seg.prod(0, 0).power == mint(1));

    assert(seg.prod(0, 1).hash == mint(3));
    assert(seg.prod(0, 1).power == B);

    assert(seg.prod(0, 2).hash == mint(3) * B + mint(1));
    assert(seg.prod(0, 2).power == B * B);

    assert(seg.prod(0, 3).hash == mint(3) * B * B + mint(1) * B + mint(4));
    assert(seg.prod(0, 3).power == B * B * B);

    assert(seg.prod(1, 3).hash == mint(1) * B + mint(4));
    assert(seg.prod(1, 3).power == B * B);
}

int main() {
    mrh::set_base(mint(100));
    test1_basic();
    test2_sequence();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
