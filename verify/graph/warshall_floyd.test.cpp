#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include <iostream>

#include "graph/warshall_floyd.hpp"
#include "graph/read_graph.hpp"

int main() {
    {
        const int n1 = 5, n2 = 5;
        Graph<int> g(n1 + n2, true);
        for (int i = 0; i < n1; i++) {
            g.add_edge(i, (i + 1) % n1, -1, i);
        }
        for (int i = 0; i < n2; i++) {
            g.add_edge(i + n1, (i + 1) % n2 + n1, -1, i + n1);
        }
        const int INF = 1 << 30;
        auto dist = warshall_floyd(g, INF);
        for (int i = 0; i < n1 + n2; i++) {
            for (int j = 0; j < n1 + n2; j++) {
                int same = (i < n1) == (j < n1);
                if (same) {
                    assert(dist[i][j] == -INF);
                } else {
                    assert(dist[i][j] == INF);
                }
            }
        }
    }
    {
        const int n1 = 5, n2 = 5;
        Graph<int> g(n1 + n2, true);
        for (int i = 0; i < n1; i++) {
            g.add_edge(i, (i + 1) % n1, -1, i);
        }
        for (int i = 0; i < n2; i++) {
            if (i % 2 == 0) {
                g.add_edge(i + n1, i, 1, i + n1);
            } else {
                g.add_edge(i, i + n1, 1, i + n1);
            }
        }
        const int INF = 1 << 30;
        auto dist = warshall_floyd(g, INF);
        for (int i = 0; i < n1 + n2; i++) {
            for (int j = 0; j < n1 + n2; j++) {
                if (i < n1 and j < n1) {
                    assert(dist[i][j] == -INF);
                } else if (i < n1) {
                    assert(j >= n1);
                    if ((j - n1) % 2 == 0) {
                        assert(dist[i][j] == INF);
                    } else {
                        assert(dist[i][j] == -INF);
                    }
                } else if (j < n1) {
                    assert(i >= n1);
                    if ((i - n1) % 2 == 0) {
                        assert(dist[i][j] == -INF);
                    } else {
                        assert(dist[i][j] == INF);
                    }
                } else {
                    assert(i >= n1 and j >= n1);
                    if (i == j) {
                        assert(dist[i][j] == 0);
                    } else if ((i - n1) % 2 == (j - n1) % 2) {
                        assert(dist[i][j] == INF);
                    } else {
                        if ((i - n1) % 2 == 0) {
                            assert(dist[i][j] == -INF);
                        } else {
                            assert(dist[i][j] == INF);
                        }
                    }
                }
            }
        }
    }
    int V, E;
    std::cin >> V >> E;
    auto g = read_graph<long long>(V, E, true, true, 0);
    const long long INF = 1LL << 60;
    auto dist = warshall_floyd(g, INF);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == -INF) {
                std::cout << "NEGATIVE CYCLE\n";
                return 0;
            }
        }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                std::cout << "INF";
            } else {
                std::cout << dist[i][j];
            }
            std::cout << " \n"[j + 1 == V];
        }
    }
    return 0;
}