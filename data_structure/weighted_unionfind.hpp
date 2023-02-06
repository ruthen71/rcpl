#pragma once

template <class T> struct weighted_unionfind {
    std::vector<int> parents;
    std::vector<T> diff_weight;

    weighted_unionfind() {}
    weighted_unionfind(int n) : parents(n, -1), diff_weight(n) {}

    int leader(int x) {
        if (parents[x] < 0) {
            return x;
        } else {
            int r = leader(parents[x]);
            diff_weight[x] += diff_weight[parents[x]];
            return parents[x] = r;
        }
    }

    T weight(int x) {
        leader(x);
        return diff_weight[x];
    }

    // weight(y) = weight(x) + w
    bool merge(int x, int y, T w) {
        w += weight(x);
        w -= weight(y);
        x = leader(x), y = leader(y);
        if (x == y) return false;
        if (parents[x] > parents[y]) std::swap(x, y), w = -w;
        parents[x] += parents[y];
        parents[y] = x;
        diff_weight[y] = w;
        return true;
    }

    // return weight(y) - weight(x)
    T diff(int x, int y) { return weight(y) - weight(x); }

    bool same(int x, int y) { return leader(x) == leader(y); }

    int size(int x) { return -parents[leader(x)]; }

    void init(int n) { parents.assign(n, -1), diff_weight.assign(n, 0); }  // reset
};

/**
 * @brief Weighted UnionFind (重みつき UnionFind)
 * @docs docs/data_structure/weighted_unionfind.md
 */