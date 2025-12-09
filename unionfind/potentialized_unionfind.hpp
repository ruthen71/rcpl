#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

// Potentialized Unionfind
template <class G> struct PotentializedUnionfind {
    static_assert(G::commutative == true);

    using T = typename G::value_type;

    int n;
    std::vector<int> parent;
    std::vector<T> value;

    PotentializedUnionfind() = default;

    explicit PotentializedUnionfind(int n)
        : n(n), parent(n, -1), value(n, G::identity()) {}

    int leader(int x) {
        assert(0 <= x and x < n);
        if (parent[x] < 0) {
            return x;
        } else {
            int r = leader(parent[x]);
            value[x] = G::operation(value[x], value[parent[x]]);
            return parent[x] = r;
        }
    }

    T potential(int x) {
        assert(0 <= x and x < n);
        leader(x);
        return value[x];
    }

    int merge(int x, int y, T d) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        // d は y の x からのポテンシャルの差分
        // d を leader(y) の leader(x) からのポテンシャルの差分に修正
        d = G::operation(G::operation(d, potential(x)),
                         G::inverse(potential(y)));
        x = leader(x);
        y = leader(y);
        if (x == y) {
            if (d == G::identity()) {
                return x;
            } else {
                return -1;
            }
        }
        if (-parent[x] < -parent[y]) {
            std::swap(x, y);
            d = G::inverse(d);
        }
        parent[x] += parent[y];
        parent[y] = x;
        value[y] = d;
        return x;
    }

    T distance(int x, int y) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        assert(same(x, y));
        return G::operation(potential(y), G::inverse(potential(x)));
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

    std::vector<std::vector<std::pair<int, T>>> groups() {
        std::vector<int> leader_buf(n), group_size(n);
        for (int i = 0; i < n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<std::pair<int, T>>> result(n);
        for (int i = 0; i < n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < n; i++) {
            result[leader_buf[i]].emplace_back(i, potential(i));
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<std::pair<int, T>>& v) {
                               return v.empty();
                           }),
            result.end());
        return result;
    }
};
