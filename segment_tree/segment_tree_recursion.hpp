#pragma once

#include <cassert>
#include <vector>

// Segment Tree (再帰 + ポインタ木)
template <class MS> struct SegmentTreeRecursion {
  public:
    using S = typename MS::value_type;

    struct Node {
        Node *l, *r;
        S d;
        Node(S v, Node* l = nullptr, Node* r = nullptr) : d(v), l(l), r(r) {}
    };

    SegmentTreeRecursion() = default;

    explicit SegmentTreeRecursion(int n)
        : SegmentTreeRecursion(std::vector<S>(n, MS::identity())) {}

    explicit SegmentTreeRecursion(const std::vector<S>& v)
        : n((int)(v.size())) {
        root = build(v, 0, n);
    }

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

    S prod(int l, int r) const { return prod(l, r, 0, n, root); }

    S all_prod() const { return root->d; }

    std::vector<S> make_vector() const {
        std::vector<S> vec(n);
        for (int i = 0; i < n; i++) vec[i] = get(i);
        return vec;
    }

  private:
    int n;
    Node* root;

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

    Node* set(int p, const S& x, int l, int r, Node* np) {
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

    Node* add(int p, const S& x, int l, int r, Node* np) {
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
        // [ql, qr) と [l, r) が交差しない
        if (qr <= l or r <= ql) return MS::identity();
        // [ql, qr) が [l, r) を完全に含んでいる
        if (ql <= l and r <= qr) return np->d;
        int m = (l + r) / 2;
        return MS::operation(prod(ql, qr, l, m, np->l),
                             prod(ql, qr, m, r, np->r));
    }
};
