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

    Node* merge(Node* l, Node* r) {
        return new Node(MS::operation(l->d, r->d), l, r);
    }

    Node* build(const std::vector<S>& v, int l, int r) {
        if (l + 1 == r) return new Node(v[l]);
        return merge(build(v, l, (l + r) / 2), build(v, (l + r) / 2, r));
    }

    void update(int qp, const S& qx, int nl, int nr, Node* np) {
        if (nl + 1 == nr) {
            np->d = qx;
            return;
        }
        int nm = (nl + nr) / 2;
        if (nl <= qp and qp < nm) update(qp, qx, nl, nm, np->l);
        if (nm <= qp and qp < nr) update(qp, qx, nm, nr, np->r);
        np->d = MS::operation(np->l->d, np->r->d);
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

    S inner_prod(int ql, int qr, int nl, int nr, Node* np) const {
        // [ql, qr) と [nl, nr) が交差しない
        if (qr <= nl or nr <= ql) return MS::identity();
        // [ql, qr) が [nl, nr) を完全に含んでいる
        if (ql <= nl and nr <= qr) return np->d;
        int nm = (nl + nr) / 2;
        return MS::operation(inner_prod(ql, qr, nl, nm, np->l),
                             inner_prod(ql, qr, nm, nr, np->r));
    }

    S all_prod() const { return root->d; }
};
