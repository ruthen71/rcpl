#pragma once

#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

#include "graph/graph_template.hpp"
#include "data_structure/unionfind.hpp"

// minimum steiner tree
// O(3 ^ k n + 2 ^ k m \log m) (n = |V|, m = |E|, k = |terminals|)
// https://www.slideshare.net/wata_orz/ss-12131479#50
// https://kopricky.github.io/code/Academic/steiner_tree.html
// https://atcoder.jp/contests/abc364/editorial/10547
template <class T> std::vector<std::vector<T>> minimum_steiner_tree(Graph<T>& g, std::vector<int>& terminals, const T inf) {
    const int n = (int)(g.size());
    const int k = (int)(terminals.size());
    const int k2 = 1 << k;

    // dp[bit][v] = ターミナルの部分集合が bit (0 ~ k - 1 に圧縮), 加えて頂点 v も含まれる最小シュタイナー木
    std::vector dp(k2, std::vector<T>(n, inf));
    for (int i = 0; i < k; i++) dp[1 << i][terminals[i]] = T(0);

    for (int bit = 0; bit < (1 << k); bit++) {
        // dp[bit][v] = min(dp[bit][v], dp[sub][v] + dp[bit ^ sub][v])
        // 通常の実装
        // for (int sub = bit; sub > 0; sub = (sub - 1) & bit) {
        // 定数倍高速化
        // bit の中で 1 要素だけ sub と bit ^ sub のどちらに属するか決める
        int bit2 = bit ^ (bit & -bit);
        for (int sub = bit2; sub > 0; sub = (sub - 1) & bit2) {
            for (int v = 0; v < n; v++) {
                dp[bit][v] = std::min(dp[bit][v], dp[sub][v] + dp[bit ^ sub][v]);
            }
        }
        // dp[bit][v] = min(dp[bit][v], dp[bit][u] + cost(u, v))
        using tp = std::pair<T, int>;
        std::priority_queue<tp, std::vector<tp>, std::greater<tp>> que;
        for (int u = 0; u < n; u++) que.emplace(dp[bit][u], u);
        while (!que.empty()) {
            auto [d, u] = que.top();
            que.pop();
            if (dp[bit][u] != d) continue;
            for (auto&& e : g[u]) {
                if (dp[bit][e.to] > d + e.cost) {
                    dp[bit][e.to] = d + e.cost;
                    que.emplace(dp[bit][e.to], e.to);
                }
            }
        }
    }
    // dp[k2 - 1][i] = ターミナルと頂点 i を含む最小シュタイナー木
    // dp[k2 - 1][terminals[0]] が基本的な答えになる
    return dp;
}

// O(2 ^ {n - k} (n + m)) (n = |V|, m = |E|, k = |terminals|)
// https://yukicoder.me/problems/no/114/editorial
// n - k <= 20, n <= 64
template <class T> T minimum_steiner_tree_mst(Graph<T>& g, std::vector<int>& terminals, const T inf) {
    const int n = (int)(g.size());
    const int k = (int)(terminals.size());
    assert(n <= 64);

    // ターミナルに含まれない点集合 (others) を取得
    unsigned long long st = 0;
    for (int i = 0; i < k; i++) st |= 1LL << terminals[i];
    std::vector<int> others;
    for (int i = 0; i < n; i++)
        if ((st >> i & 1) == 0) others.emplace_back(i);

    // 辺のリスト
    std::vector<Edge<T>> edges;
    for (int v = 0; v < n; v++) {
        for (auto&& e : g[v]) {
            edges.push_back(e);
        }
    }
    std::sort(edges.begin(), edges.end(), [&](Edge<T>& a, Edge<T>& b) -> bool { return a.cost < b.cost; });

    // ターミナル + others の組合せを全列挙 -> Minimum Spanning Tree を求める
    T ans = inf;
    for (int bit = 0; bit < (1 << (n - k)); bit++) {
        // 使う頂点集合
        unsigned long long subv = st;
        for (int i = 0; i < n - k; i++) {
            if (bit >> i & 1) {
                subv |= 1LL << others[i];
            }
        }

        // Minimum Spanning Tree を計算
        UnionFind uf(n);
        T cur = 0;
        int connected = 0;
        for (auto&& e : edges) {
            // subv に対する g の誘導部分グラフに含まれる辺のみ試す
            if (!(subv >> e.from & 1) or !(subv >> e.to & 1)) continue;
            if (!uf.same(e.from, e.to)) {
                uf.merge(e.from, e.to);
                cur += e.cost;
                connected++;
            }
        }
        // 全域木が作れたか判定
        if (connected + 1 == k + __builtin_popcount(bit)) ans = std::min(ans, cur);
    }
    return ans;
}