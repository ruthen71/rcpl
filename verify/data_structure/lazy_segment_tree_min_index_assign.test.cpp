#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <iostream>
#include <limits>

#include "../../algebra/acted_monoid/acted_monoid_max_index_assign.hpp"
#include "../../algebra/acted_monoid/acted_monoid_min_index_assign.hpp"
#include "../../data_structure/lazy_segment_tree.hpp"

constexpr int INF = std::numeric_limits<int>::max();
constexpr int NONE = INF - 1;

void test1_basic() {
    using AMMin = ActedMonoidMinIndexAssign<int, INF, true, NONE>;
    assert((AMMin::MS::identity().v == INF));
    assert((AMMin::MS::identity().i == -1));
    assert((AMMin::MS::commutative == true));
    assert((AMMin::MF::identity() == NONE));
    assert((AMMin::MF::commutative == false));

    using AMMax = ActedMonoidMaxIndexAssign<int, INF, true, NONE>;
    assert((AMMax::MS::identity().v == -INF));
    assert((AMMax::MS::identity().i == -1));
    assert((AMMax::MS::commutative == true));
    assert((AMMax::MF::identity() == NONE));
    assert((AMMax::MF::commutative == false));
}

void test2_query() {
    // a = {3, 1, 4, 1, 5}
    std::vector<ValueIndex<int>> a_min = {
        {3, 0}, {1, 1}, {4, 2}, {1, 3}, {5, 4}};
    std::vector<ValueIndex<int>> a_max = {
        {-3, 0}, {-1, 1}, {-4, 2}, {-1, 3}, {-5, 4}};
    LazySegmentTree<ActedMonoidMinIndexAssign<int, INF, true, NONE>> segmin(
        a_min);
    LazySegmentTree<ActedMonoidMaxIndexAssign<int, INF, true, NONE>> segmax(
        a_max);

    // []
    assert(segmin.prod(0, 0).v == INF);
    assert(segmin.prod(0, 0).i == -1);
    assert(segmax.prod(0, 0).v == -INF);
    assert(segmax.prod(0, 0).i == -1);
    // [3, 1]
    assert(segmin.prod(0, 2).v == 1);
    assert(segmin.prod(0, 2).i == 1);
    assert(segmax.prod(0, 2).v == -1);
    assert(segmax.prod(0, 2).i == 1);

    // [3, 1, 4, 1, 5]
    assert(segmin.prod(0, 5).v == 1);
    assert(segmin.prod(0, 5).i == 1);  // left = true
    assert(segmax.prod(0, 5).v == -1);
    assert(segmax.prod(0, 5).i == 1);  // left = true

    // apply +10 to [0, 3)
    // a = {10, 10, 10, 1, 5}
    segmin.apply(0, 3, 10);
    segmax.apply(0, 3, -10);
    assert(segmin.prod(0, 5).v == 1);
    assert(segmin.prod(0, 5).i == 3);
    assert(segmax.prod(0, 5).v == -1);
    assert(segmax.prod(0, 5).i == 3);

    // apply -20 to [2, 5)
    segmin.apply(2, 5, -20);
    segmax.apply(2, 5, 20);
    // a = {10, 10, -20, -20, -20}
    assert(segmin.prod(0, 5).v == -20);
    assert(segmin.prod(0, 5).i == 2);
    assert(segmax.prod(0, 5).v == 20);
    assert(segmax.prod(0, 5).i == 2);
}

void test3_smaller_index() {
    std::vector<ValueIndex<int>> a_min = {{1, 0}, {1, 1}};
    std::vector<ValueIndex<int>> a_max = {{1, 0}, {1, 1}};
    LazySegmentTree<ActedMonoidMinIndexAssign<int, INF, true, NONE>> segmin(
        a_min);
    LazySegmentTree<ActedMonoidMaxIndexAssign<int, INF, true, NONE>> segmax(
        a_max);
    assert(segmin.all_prod().i == 0);
    assert(segmax.all_prod().i == 0);
}

void test4_not_smaller_index() {
    std::vector<ValueIndex<int>> a_min = {{1, 0}, {1, 1}};
    std::vector<ValueIndex<int>> a_max = {{1, 0}, {1, 1}};
    LazySegmentTree<ActedMonoidMinIndexAssign<int, INF, false, NONE>> segmin(
        a_min);
    LazySegmentTree<ActedMonoidMaxIndexAssign<int, INF, false, NONE>> segmax(
        a_max);
    assert(segmin.all_prod().i == 1);
    assert(segmax.all_prod().i == 1);
}

int main() {
    test1_basic();
    test2_query();
    test3_smaller_index();
    test4_not_smaller_index();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
