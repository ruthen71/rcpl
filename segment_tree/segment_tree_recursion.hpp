#pragma once

#include <cassert>

// Segment Tree (再帰 + ポインタ木)
template <class MS> struct SegmentTreeRecursion {
    using S = typename MS::value_type;

    struct Node {
        Node *l, *r;
        S d;
        Node(S v, Node* l = nullptr, Node* r = nullptr) : d(v), l(l), r(r) {}
    };
    int n;
    Node* root;

    SegmentTreeRecursion() = default;

    explicit SegmentTreeRecursion(int n)
        : SegmentTreeRecursion(std::vector<S>(n, MS::identity())) {}

    explicit SegmentTreeRecursion(const std::vector<S>& v)
        : n((int)(v.size())) {
        root = build(v, 0, n);
    }

    Node* merge(Node* l, Node* r, Node* np = nullptr) {
        if (np == nullptr) {
            np = new Node(MS::operation(l->d, r->d), l, r);
        } else {
            np->d = MS::operation(l->d, r->d);
        }
        return np;
    }

    Node* build(const std::vector<S>& v, int l, int r) {
        if (l + 1 == r) {
            return new Node(v[l]);
        }
        int m = (l + r) / 2;
        return merge(build(v, l, m), build(v, m, r));
    }

    Node* update(int p, const S& x, int l, int r, Node* np) {
        if (l + 1 == r) {
            np->d = x;
            return np;
        }
        int m = (l + r) / 2;
        if (l <= p and p < m) {
            return merge(update(p, x, l, m, np->l), np->r, np);
        } else {
            return merge(np->l, update(p, x, m, r, np->r), np);
        }
    }

    void set(int p, const S& x) {
        assert(0 <= p and p < n);
        update(p, x, 0, n, root);
    }

    S operator[](int p) const {
        assert(0 <= p and p < n);
        return prod(p, p + 1);
    }

    S get(int p) const {
        assert(0 <= p and p < n);
        return prod(p, p + 1);
    }

    S prod(int l, int r) const { return inner_prod(l, r, 0, n, root); }

    S inner_prod(int ql, int qr, int l, int r, Node* np) const {
        // [ql, qr) と [l, r) が交差しない
        if (qr <= l or r <= ql) return MS::identity();
        // [ql, qr) が [l, r) を完全に含んでいる
        if (ql <= l and r <= qr) return np->d;
        int m = (l + r) / 2;
        return MS::operation(inner_prod(ql, qr, l, m, np->l),
                             inner_prod(ql, qr, m, r, np->r));
    }

    S all_prod() const { return root->d; }
};
