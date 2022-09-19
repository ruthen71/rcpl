#pragma once

template <class T> T histogram_largest_rectangle(std::vector<T> &h) {
    int n = (int)h.size();
    std::vector<int> st(n), L(n), R(n);
    int t = 0;
    for (int i = 0; i < n; i++) {
        while (t > 0 and h[st[t - 1]] >= h[i]) t--;
        L[i] = (t == 0 ? 0 : st[t - 1] + 1);
        st[t++] = i;
    }
    t = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (t > 0 and h[st[t - 1]] >= h[i]) t--;
        R[i] = (t == 0 ? n : st[t - 1]);
        st[t++] = i;
    }
    T res = 0;
    for (int i = 0; i < n; i++) res = std::max(res, h[i] * (R[i] - L[i]));
    return res;
}
