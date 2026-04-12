#pragma once

#include <cassert>
#include <vector>

// Persistent Segment Tree
template <class MS> struct PersistentSegmentTree {
  public:
    using S = typename MS::value_type;

    struct Node {
        Node *l, *r;
        S d;
        Node(S v, Node* l = nullptr, Node* r = nullptr) : d(v), l(l), r(r) {}
    };

    PersistentSegmentTree() = default;

    explicit PersistentSegmentTree(int n)
        : PersistentSegmentTree(std::vector<S>(n, MS::identity())) {}

    explicit PersistentSegmentTree(const std::vector<S>& v)
        : n((int)(v.size())) {
        roots.push_back(build(v, 0, n));
    }

    int get_time() { return (int)(roots.size()) - 1; }

    Node* set(int p, const S& x, Node* root) {
        assert(0 <= p and p < n);
        roots.push_back(set(p, x, 0, n, root));
        return roots.back();
    }

    Node* set(int p, const S& x) { return set(p, x, roots.back()); }

    Node* set(int p, const S& x, int t) {
        assert(0 <= t and t < (int)(roots.size()));
        return set(p, x, roots[t]);
    }

    Node* add(int p, const S& x, Node* root) {
        assert(0 <= p and p < n);
        roots.push_back(add(p, x, 0, n, root));
        return roots.back();
    }

    Node* add(int p, const S& x) { return add(p, x, roots.back()); }

    Node* add(int p, const S& x, int t) {
        assert(0 <= t and t < (int)(roots.size()));
        return add(p, x, roots[t]);
    }

    S get(int p, Node* root) const {
        assert(0 <= p and p < n);
        return prod(p, p + 1, root);
    }

    S get(int p) const { return get(p, roots.back()); }

    S get(int p, int t) const {
        assert(0 <= t and t < (int)(roots.size()));
        return get(p, roots[t]);
    }

    S operator[](int p) const {
        assert(0 <= p and p < n);
        return prod(p, p + 1);
    }

    S prod(int l, int r, Node* root) const { return prod(l, r, 0, n, root); }

    S prod(int l, int r) const { return prod(l, r, roots.back()); }

    S prod(int l, int r, int t) const {
        assert(0 <= t and t < (int)(roots.size()));
        return prod(l, r, roots[t]);
    }

    S all_prod(Node* root) const { return root->d; }

    S all_prod() const { return all_prod(roots.back()); }

    S all_prod(int t) const {
        assert(0 <= t and t < (int)(roots.size()));
        return all_prod(roots[t]);
    }

    std::vector<S> make_vector(Node* root) const {
        std::vector<S> vec(n);
        for (int i = 0; i < n; i++) vec[i] = get(i, root);
        return vec;
    }

    std::vector<S> make_vector() const { return make_vector(roots.back()); }

    std::vector<S> make_vector(int t) const {
        assert(0 <= t and t < (int)(roots.size()));
        return make_vector(roots[t]);
    }

  private:
    int n;
    std::vector<Node*> roots;

    Node* merge(Node* l, Node* r) {
        return new Node(MS::operation(l->d, r->d), l, r);
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
            return new Node(x);
        }
        int m = (l + r) / 2;
        if (l <= p and p < m) {
            return merge(set(p, x, l, m, np->l), np->r);
        } else {
            return merge(np->l, set(p, x, m, r, np->r));
        }
    }

    Node* add(int p, const S& x, int l, int r, Node* np) {
        if (l + 1 == r) {
            return new Node(MS::operation(np->d, x));
        }
        int m = (l + r) / 2;
        if (l <= p and p < m) {
            return merge(add(p, x, l, m, np->l), np->r);
        } else {
            return merge(np->l, add(p, x, m, r, np->r));
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
