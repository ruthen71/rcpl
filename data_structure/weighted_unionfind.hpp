#pragma once

template <class T> struct WeightedUnionFind {
    int n;
    std::vector<int> parents;
    std::vector<T> diff_weight;

    WeightedUnionFind() {}
    WeightedUnionFind(int n) : n(n), parents(n, -1), diff_weight(n, T(0)) {}

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

    // 連結成分ごとに (頂点番号 v, diff(leader(v), v)) の配列を返す
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
            result[leader_buf[i]].emplace_back(i, weight(i));
        }
        result.erase(std::remove_if(result.begin(), result.end(), [&](const std::vector<std::pair<int, T>>& v) { return v.empty(); }), result.end());
        return result;
    }

    void init(int n) { parents.assign(n, -1), diff_weight.assign(n, T(0)); }  // reset
};