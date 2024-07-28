#pragma once

#include <vector>
#include <cassert>

template <class T> struct Edge {
    int from, to;
    T cost;
    int id;

    Edge() = default;
    Edge(const int from, const int to, const T cost = T(1), const int id = -1) : from(from), to(to), cost(cost), id(id) {}

    friend std::ostream& operator<<(std::ostream& os, const Edge<T>& e) {
        // output format: {id: cost(from, to) = cost}
        return os << "{" << e.id << ": cost(" << e.from << ", " << e.to << ") = " << e.cost << "}";
    }
};
template <class T> using Edges = std::vector<Edge<T>>;

template <class T> struct Graph {
    struct EdgeIterators {
       public:
        using Iterator = typename std::vector<Edge<T>>::iterator;
        EdgeIterators() = default;
        EdgeIterators(const Iterator& begit, const Iterator& endit) : begit(begit), endit(endit) {}
        Iterator begin() const { return begit; }
        Iterator end() const { return endit; }
        size_t size() const { return std::distance(begit, endit); }
        Edge<T>& operator[](int i) const { return begit[i]; }

       private:
        Iterator begit, endit;
    };

    int n, m;
    bool is_build, is_directed;
    std::vector<Edge<T>> edges;
    // CSR (Compressed Row Storage) 形式用
    std::vector<int> start;
    std::vector<Edge<T>> csr_edges;

    Graph() : Graph(0) {}
    Graph(const int n, const bool directed = false) : n(n), m(0), is_build(false), start(n + 1, 0), is_directed(directed) {}

    // 辺を追加し, その辺が何番目に追加されたかを返す
    int add_edge(const int from, const int to, const T cost = T(1), int id = -1) {
        assert(!is_build);
        assert(0 <= from and from < n);
        assert(0 <= to and to < n);
        if (id == -1) id = m;
        edges.emplace_back(from, to, cost, id);
        return m++;
    }

    // CSR 形式でグラフを構築
    void build() {
        assert(!is_build);
        for (auto&& e : edges) {
            start[e.from + 1]++;
            if (!is_directed) start[e.to + 1]++;
        }
        for (int v = 0; v < n; v++) start[v + 1] += start[v];
        auto counter = start;
        csr_edges.resize(start.back() + 1);
        for (auto&& e : edges) {
            csr_edges[counter[e.from]++] = e;
            if (!is_directed) csr_edges[counter[e.to]++] = Edge(e.to, e.from, e.cost, e.id);
        }
        is_build = true;
    }

    EdgeIterators operator[](int i) {
        if (!is_build) build();
        return EdgeIterators(csr_edges.begin() + start[i], csr_edges.begin() + start[i + 1]);
    }

    size_t size() const { return (size_t)(n); }

    friend std::ostream& operator<<(std::ostream& os, Graph<T>& g) {
        // output format: {id: cost(from, to) = cost}
        os << "[";
        for (int i = 0; i < g.size(); i++) {
            os << "[";
            for (int j = 0; j < g[i].size(); j++) {
                os << g[i][j];
                if (j + 1 != g[i].size()) os << ", ";
            }
            os << "]";
            if (i + 1 != g.size()) os << ", ";
        }
        return os << "]";
    }
};