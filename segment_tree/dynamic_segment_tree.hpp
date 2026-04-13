#pragma once

#include <cassert>
#include <vector>

// Dynamic Segment Tree
// Q log_2(N) は Q = 500000, N = 10^18 のとき 30000000 くらい
template <class MS, int MAX_NODES = 30'000'000> struct DynamicSegmentTree {
  public:
    using S = typename MS::value_type;

    struct Node {
        S d;
        Node *l, *r;
        Node() = default;
        Node(S v, Node* l = nullptr, Node* r = nullptr) : d(v), l(l), r(r) {}
    };

    DynamicSegmentTree() = default;

    explicit DynamicSegmentTree(int n) : n(n), root(nullptr) {}

    void set(int p, const S& x) {
        assert(0 <= p and p < n);
        set(p, x, 0, n, root);
    }

    void add(int p, const S& x) {
        assert(0 <= p and p < n);
        add(p, x, 0, n, root);
    }

    S operator[](int p) const {
        assert(0 <= p and p < n);
        return prod(p, p + 1);
    }

    S get(int p) const {
        assert(0 <= p and p < n);
        return prod(p, p + 1);
    }

    S prod(int l, int r) const {
        assert(0 <= l and l <= r and r <= n);
        return prod(l, r, 0, n, root);
    }

    S all_prod() const { return (root == nullptr ? MS::identity() : root->d); }

    std::vector<std::pair<int, S>> make_vector() const {
        std::vector<std::pair<int, S>> vec;
        auto rec = [&](auto f, int l, int r, Node* np) -> void {
            if (np == nullptr) return;
            if (l + 1 == r) vec.push_back({l, np->d});
            int m = (l + r) / 2;
            f(f, l, m, np->l);
            f(f, m, r, np->r);
        };
        rec(rec, 0, n, root);
        return vec;
    }

  private:
    int n;
    Node* root;
    static inline Node pool[MAX_NODES];
    static inline int pool_idx = 0;

    Node* new_node(S v, Node* l = nullptr, Node* r = nullptr) {
        return &(pool[pool_idx++] = Node(v, l, r));
    }

    Node* merge(Node* l, Node* r, Node* np) {
        np->d = MS::operation((l == nullptr ? MS::identity() : l->d),
                              (r == nullptr ? MS::identity() : r->d));
        return np;
    }

    Node* set(int p, const S& x, int l, int r, Node*& np) {
        if (np == nullptr) {
            np = new_node(MS::identity());
        }
        if (l + 1 == r) {
            np->d = x;
            return np;
        }
        int m = (l + r) / 2;
        if (l <= p and p < m) {
            return merge(set(p, x, l, m, np->l), np->r, np);
        } else {
            return merge(np->l, set(p, x, m, r, np->r), np);
        }
    }

    Node* add(int p, const S& x, int l, int r, Node*& np) {
        if (np == nullptr) {
            np = new_node(MS::identity());
        }
        if (l + 1 == r) {
            np->d = MS::operation(np->d, x);
            return np;
        }
        int m = (l + r) / 2;
        if (l <= p and p < m) {
            return merge(add(p, x, l, m, np->l), np->r, np);
        } else {
            return merge(np->l, add(p, x, m, r, np->r), np);
        }
    }

    S prod(int ql, int qr, int l, int r, Node* np) const {
        if (np == nullptr) return MS::identity();
        //  [ql, qr) と [l, r) が交差しない
        if (qr <= l or r <= ql) return MS::identity();
        // [ql, qr) が [l, r) を完全に含んでいる
        if (ql <= l and r <= qr) return np->d;
        int m = (l + r) / 2;
        return MS::operation(prod(ql, qr, l, m, np->l),
                             prod(ql, qr, m, r, np->r));
    }
};
