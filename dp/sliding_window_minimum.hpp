#pragma once

template <class T> std::vector<T> sliding_window_minimum(const std::vector<T> &a, const int k) {
    int n = (int)a.size();
    std::vector<T> res(n - k + 1);
    std::deque<T> deq;
    for (int i = 0; i < n; i++) {
        while (!deq.empty() and a[deq.back()] >= a[i]) deq.pop_back();
        deq.push_back(i);
        if (i - k + 1 >= 0) {
            res[i - k + 1] = a[deq.front()];
            if (deq.front() == i - k + 1) deq.pop_front();
        }
    }
    return res;
}