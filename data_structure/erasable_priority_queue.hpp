#pragma once

#include <queue>
#include <cassert>

// 削除可能な優先度付きキュー
// キューに含まれていない要素を削除しようとした場合壊れる
// std::multiset よりも定数倍が良い
template <class T, class Container = std::vector<T>, class Compare = std::less<T>> struct ErasablePriorityQueue {
   private:
    std::priority_queue<T, Container, Compare> que, erase_que;
    void reduce() {
        while (que.size() and erase_que.size()) {
            if (que.top() == erase_que.top()) {
                que.pop();
                erase_que.pop();
            } else {
                // Compare = std::less<T> なら que.top() < erase_que.top()
                // Compare()(que.top(), erase_que.top()) == true
                assert(!Compare()(que.top(), erase_que.top()));
                break;
            }
        }
    }

   public:
    size_t size() const {
        assert(que.size() >= erase_que.size());
        return que.size() - erase_que.size();
    }
    void push(const T t) { que.push(t); }
    void erase(const T t) { erase_que.push(t); }
    const T& top() {
        reduce();
        return que.top();
    }
    void pop() {
        reduce();
        que.pop();
    }
};
// ErasablePriorityQueue<int, std::vector<int>, std::greater<int>> que; // 最小のものから取り出せる