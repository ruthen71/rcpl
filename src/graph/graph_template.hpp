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

template <class T> using edges = std::vector<edge<T>>;
template <class T> using graph = std::vector<std::vector<edge<T>>>;
