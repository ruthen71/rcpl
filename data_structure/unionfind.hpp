#pragma once

struct UnionFind {
    int n;
    std::vector<int> parents;

    UnionFind() {}
    UnionFind(int n) : n(n), parents(n, -1) {}

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

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(n), group_size(n);
        for (int i = 0; i < n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(n);
        for (int i = 0; i < n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(std::remove_if(result.begin(), result.end(), [&](const std::vector<int>& v) { return v.empty(); }), result.end());
        return result;
    }

    void init(int n) { parents.assign(n, -1); }  // reset
};