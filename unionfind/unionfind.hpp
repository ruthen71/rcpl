#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

// Unionfind
struct Unionfind {
    int n;
    std::vector<int> parent;

    Unionfind() = default;

    explicit Unionfind(int n) : n(n), parent(n, -1) {}

    int leader(int x) {
        assert(0 <= x and x < n);
        if (parent[x] < 0) {
            return x;
        } else {
            return parent[x] = leader(parent[x]);
        }
    }

    int merge(int x, int y) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return x;
        }
        if (-parent[x] < -parent[y]) {
            std::swap(x, y);
        }
        parent[x] += parent[y];
        parent[y] = x;
        return x;
    }

    bool same(int x, int y) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        return leader(x) == leader(y);
    }

    int size(int x) {
        assert(0 <= x and x < n);
        return -parent[leader(x)];
    }

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
        result.erase(std::remove_if(
                         result.begin(), result.end(),
                         [&](const std::vector<int>& v) { return v.empty(); }),
                     result.end());
        return result;
    }
};
