#pragma once

#include <vector>

// https://onlinejudge.u-aizu.ac.jp/problems/3333

template <class T, int B = 32> class BinaryTrie {
   public:
    struct Node {
        int size;
        int l, r;
        Node() : size(0), l(-1), r(-1) {}
        friend std::ostream& operator<<(std::ostream& os, const Node& v) { return os << "{ " << v.size << ", " << v.l << ", " << v.r << " }"; }
    };
    std::vector<Node> nodes;

    BinaryTrie() : nodes(std::vector<Node>(0)) { nodes.push_back(Node()); }

    void insert(T val) { add(0, val); }
    void erase(T val) { sub(0, val); }
    T min_element(T x) { return get_min(0, x); }
    T max_element(T x) { return get_min(0, ~x); }

   private:
    int add(int id, T val, int b = B - 1) {
        if (id == -1) {
            id = int(nodes.size());
            nodes.push_back(Node());
        }
        nodes[id].size++;
        if (b < 0) return id;
        if (val >> b & 1) {
            nodes[id].r = add(nodes[id].r, val, b - 1);
        } else {
            nodes[id].l = add(nodes[id].l, val, b - 1);
        }
        return id;
    }

    int sub(int id, T val, int b = B - 1) {
        assert(id != -1);
        nodes[id].size--;
        if (b < 0) return id;
        if (val >> b & 1) {
            nodes[id].r = sub(nodes[id].r, val, b - 1);
        } else {
            nodes[id].l = sub(nodes[id].l, val, b - 1);
        }
        return id;
    }

    T get_min(int id, T val, int b = B - 1) {
        assert(id != -1);
        if (b < 0) return 0;
        int i = val >> b & 1;
        if (i == 1 and (nodes[id].r == -1 or nodes[nodes[id].r].size == 0)) i = 0;
        if (i == 0 and (nodes[id].l == -1 or nodes[nodes[id].l].size == 0)) i = 1;
        int diff = (val >> b & 1) != i;
        if (i == 1) {
            return get_min(nodes[id].r, val, b - 1) ^ (diff << b);
        } else {
            return get_min(nodes[id].l, val, b - 1) ^ (diff << b);
        }
    }
};