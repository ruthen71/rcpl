#pragma once

struct unionfind {
    std::vector<int> parents;

    unionfind() {}
    unionfind(int n) : parents(n, -1) {}

    int leader(int x) { return parents[x] < 0 ? x : parents[x] = leader(parents[x]); }

    bool merge(int x, int y) {
        x = leader(x), y = leader(y);
        if (x == y) return false;
        if (parents[x] > parents[y]) std::swap(x, y);
        parents[x] += parents[y];
        parents[y] = x;
        return true;
    }

    bool same(int x, int y) { return leader(x) == leader(y); }

    int size(int x) { return -parents[leader(x)]; }

    void init(int n) { parents.assign(n, -1); }  // reset
};

/**
 * @brief UnionFind
 * @docs docs/data-structure/unionfind.md
 */
