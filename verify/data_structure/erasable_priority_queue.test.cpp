#define PROBLEM "https://atcoder.jp/contests/abc342/tasks/abc342_g"

#include <iostream>
#include "data_structure/erasable_priority_queue.hpp"
#include "data_structure/enumerate_segment_tree_nodes.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    // 削除可能な priority_queue を乗せたセグ木を作成
    int log = 0;
    while ((1 << log) < N) log++;
    int size = 1 << log;
    std::vector<ErasablePriorityQueue<int>> d(size << 1);
    for (int i = 0; i < N; i++) d[i + size].push(A[i]);

    int Q;
    std::cin >> Q;
    std::vector<int> l(Q, -1), r(Q, -1), x(Q, -1), id(Q, -1);
    for (int qq = 0; qq < Q; qq++) {
        int type;
        std::cin >> type;
        if (type == 1) {
            std::cin >> l[qq] >> r[qq] >> x[qq];
            l[qq]--;
            auto nodes = enumerate_segment_tree_range_covering_nodes(size, l[qq], r[qq]);
            for (auto&& i : nodes) d[i].push(x[qq]);
        } else if (type == 2) {
            std::cin >> id[qq];
            id[qq]--;
            auto nodes = enumerate_segment_tree_range_covering_nodes(size, l[id[qq]], r[id[qq]]);
            for (auto&& i : nodes) d[i].erase(x[id[qq]]);
        } else {
            std::cin >> id[qq];
            id[qq]--;
            auto nodes = enumerate_segment_tree_point_containing_nodes(size, id[qq]);
            int mx = 0;
            for (auto&& i : nodes) {
                if (d[i].size() > 0) mx = std::max(mx, d[i].top());
            }
            std::cout << mx << '\n';
        }
    }
    return 0;
}