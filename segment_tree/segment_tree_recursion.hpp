#pragma once

#include "../misc/bit_ceil.hpp"
#include "../misc/countr_zero.hpp"

#include <cassert>
#include <vector>

// Segment Tree (再帰 + ポインタ木)
template <class MS> struct RecursionSegmentTree {
    using S = typename MS::value_type;
    struct Node {
        Node *l, *r;
        S d;
    };
    int n, size;
    Node* root;

    RecursionSegmentTree() = default;

    explicit RecursionSegmentTree(int n)
        : RecursionSegmentTree(std::vector<S>(n, MS::identity())) {}

    explicit RecursionSegmentTree(const std::vector<S>& v)
        : n((int)(v.size())) {
        size = bit_ceil(n);
        root = new Node;
        build(0, size, root, v);
    }

    void build(int l, int r, Node* node_p, const std::vector<S>& v) {
        if (l + 1 == r) {
            if (l < n) {
                node_p->d = v[l];
            } else {
                node_p->d = MS::identity();
            }
            return;
        }
        int m = (l + r) / 2;
        node_p->l = new Node;
        node_p->r = new Node;
        build(l, m, node_p->l, v);
        build(m, r, node_p->r, v);
        node_p->d = MS::operation(node_p->l->d, node_p->r->d);
        return;
    }

    void update(int query_p, const S& query_x, int l, int r, Node* node_p) {
        if (l + 1 == r) {
            node_p->d = query_x;
            return;
        }
        int m = (l + r) / 2;
        if (l <= query_p and query_p < m)
            update(query_p, query_x, l, m, node_p->l);
        if (m <= query_p and query_p < r)
            update(query_p, query_x, m, r, node_p->r);
        node_p->d = MS::operation(node_p->l->d, node_p->r->d);
    }

    void set(int p, const S& x) {
        assert(0 <= p and p < n);
        update(p, x, 0, size, root);
    }

    S get(int p) {
        assert(0 <= p and p < n);
        return prod(p, p + 1);
    }

    S prod(int l, int r) { return prod(l, r, 0, size, root); }

    S prod(int query_l, int query_r, int node_l, int node_r, Node* node_p) {
        // [query_l, query_r) と [node_l, node_r) が交差しない
        if (query_r <= node_l or node_r <= query_l) return MS::identity();
        // [query_l, query_r) が [node_l, node_r) を完全に含んでいる
        if (query_l <= node_l and node_r <= query_r) return node_p->d;
        int node_m = (node_l + node_r) / 2;
        return MS::operation(prod(query_l, query_r, node_l, node_m, node_p->l),
                             prod(query_l, query_r, node_m, node_r, node_p->r));
    }
};
