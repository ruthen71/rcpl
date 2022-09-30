#pragma once

template <class T> struct edge {
    int from, to;
    T cost;
    int id;

    edge(int from, int to, T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}

    friend std::ostream &operator<<(std::ostream &os, const edge<T> &e) {
        // { id : from -> to, cost }
        return os << "{ " << e.id << " : " << e.from << " -> " << e.to << ", " << e.cost << " }";
    }
};

template <class T, bool directed = false> struct graph {
    int N, M;
    using cost_type = T;
    using edge_type = edge<T>;
    std::vector<std::vector<edge_type>> G;
    std::vector<edge_type> es;

    graph() : N(0), M(0) {}
    graph(int N) : N(N), M(0), G(N) {}

    constexpr bool is_directed() { return directed; }

    size_t size() const { return G.size(); }

    void read_tree(bool weight = false, int offset = 1) { read_graph(N - 1, weight, offset); }

    void read_graph(int _M, bool weight = false, int offset = 1) {
        es.reserve(_M);
        for (int i = 0; i < _M; i++) {
            int a, b;
            std::cin >> a >> b;
            a -= offset, b -= offset;
            if (weight) {
                T c;
                std::cin >> c;
                add_edge(a, b, c);
            } else {
                add_edge(a, b);
            }
        }
    }

    void read_parent(int offset = 1) {
        es.reserve(N - 1);
        for (int i = 1; i < N; i++) {
            int p;
            std::cin >> p;
            p -= offset;
            add_edge(i, p);
        }
    }

    void add_edge(const int &a, const int &b, T cost = 1) {
        assert(0 <= a and a < N and 0 <= b and b < N);
        if (!directed) G[b].push_back(edge_type(b, a, cost, M));
        G[a].push_back(edge_type(a, b, cost, M));
        es.push_back(edge_type(a, b, cost, M++));
    }

    inline std::vector<edge_type> &operator[](const int &k) { return G[k]; }

    inline const std::vector<edge_type> &operator[](const int &k) const { return G[k]; }

    friend std::ostream &operator<<(std::ostream &os, const graph<T, directed> &G) {
        os << "V: " << G.N << "\nE: " << G.M << '\n';
        for (int v = 0; v < G.N; v++) {
            os << "G[" << v << "] = [";
            for (auto &e : G[v]) os << e << " ";
            os << "]\n";
        }
        return os;
    }
};