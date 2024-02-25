#pragma once
#include <queue>

// 要素が含まれていることが保証されている場合に削除可能な優先度付きキュー
// std::multiset よりも定数倍が良い
// ErasablePriorityQueue<int, std::greater<int>> とすれば最小のものから順に取り出せる
template <class T, class F = std::less<T>> struct ErasablePriorityQueue {
   private:
    std::priority_queue<T, std::vector<T>, F> que, erase_que;
    void reduce() {
        while (que.size() and erase_que.size() and que.top() == erase_que.top()) {
            que.pop();
            erase_que.pop();
        }
    }

   public:
    size_t size() const {
        assert(que.size() >= erase_que.size());
        return que.size() - erase_que.size();
    }
    void push(const T& t) { que.push(t); }
    void erase(const T& t) { erase_que.push(t); }
    const T& top() {
        reduce();
        return que.top();
    }
    void pop() {
        reduce();
        que.pop();
    }
};
