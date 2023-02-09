#pragma once

template <class T> struct Edge {
    int from, to;
    T cost;
    int id;

    Edge() = default;
    Edge(int from, int to, T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}

    friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {
        // output format: "{ id : from -> to, cost }"
        return os << "{ " << e.id << " : " << e.from << " -> " << e.to << ", " << e.cost << " }";
    }
};

template <class T> using Edges = std::vector<Edge<T>>;
template <class T> using Graph = std::vector<std::vector<Edge<T>>>;
