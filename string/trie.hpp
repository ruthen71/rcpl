#pragma once

#include <array>
#include <string>
#include <vector>

template <int CharSize = 26, int Base = 'a'> struct Trie {
    struct Node {
        std::array<int, CharSize> next;  // 子 Node の id (-1 で初期化)
        std::vector<int> accept;         // この Node で終わる文字列の id
        int val;                         // Node が持つ文字 (-Base)
        int common;                      // Node を通る文字列の個数
        Node(int val = -1) : val(val), common(0) { next.fill(-1); }
    };

    std::vector<Node> nodes;
    int root;

    Trie() : root(0) { nodes.push_back(Node(-1)); }

    // s[word_id] に対応する Node が next_id
    void update_child(int node_id, int next_id, int word_id) {
        nodes[node_id].common++;
        return;
    }

    // s[-1] に対応する Node が node_id
    void update_direct(int node_id, int word_id) {
        nodes[node_id].accept.push_back(word_id);
        return;
    }

    // 文字列 s を追加
    void insert(const std::string& s) {
        int word_id = nodes[root].common, node_id = root;
        for (int i = 0; i < (int)(s.size()); i++) {
            int val = (int)(s[i] - Base);
            int next_id = nodes[node_id].next[val];
            if (next_id == -1) {
                // make new node
                next_id = (int)(nodes.size());
                nodes.push_back(Node(val));
            }
            update_child(node_id, next_id, word_id);
            nodes[node_id].next[val] = next_id;
            node_id = next_id;
        }
        update_child(node_id, -1, word_id);
        update_direct(node_id, word_id);
        return;
    }

    // 文字列 s の個数
    int count(const std::string& s, bool prefix = false) {
        int node_id = root;
        for (int i = 0; i < (int)(s.size()); i++) {
            int val = (int)(s[i] - Base);
            int next_id = nodes[node_id].next[val];
            if (next_id == -1) {
                return 0;
            }
            node_id = next_id;
        }
        return prefix ? nodes[node_id].common : (int)(nodes[node_id].accept.size());
    }

    // 文字列 s で始まる文字列の個数
    int count_prefix(const std::string& s) { return count(s, true); }

    // 追加した文字列の個数
    int count() const { return nodes[root].common; }

    // ノード数
    int size() const { return (int)(nodes.size()); }
};