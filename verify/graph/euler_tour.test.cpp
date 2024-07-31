#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/euler_tour.hpp"
#include "data_structure/segment_tree.hpp"
#include "algebra/monoid_s/monoid_sum.hpp"

int main() {
    int N;
    std::cin >> N;
    Graph<int> g(N);

    std::vector<int> id(N, -1);
    for (int i = 0; i < N; i++) {
        int K;
        std::cin >> K;
        for (int j = 0; j < K; j++) {
            int c;
            std::cin >> c;
            id[c] = g.add_edge(i, c, 0);
        }
    }

    EulerTour et(g);
    SegmentTree<MonoidSum<long long>> seg(2 * N - 2);
    int Q;
    std::cin >> Q;
    for (int q = 0; q < Q; q++) {
        int type;
        std::cin >> type;
        if (type == 0) {
            int v, w;
            std::cin >> v >> w;
            int eid = id[v];
            seg.chset(et.esl[eid], w);
            seg.chset(et.esr[eid], -w);
        } else {
            int u;
            std::cin >> u;
            std::cout << seg.prod(0, et.vsl[u]) << '\n';
        }
    }
    return 0;
}