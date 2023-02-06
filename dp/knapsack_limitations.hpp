#pragma once

template <class T, class F = std::greater<T>>
std::vector<T> knapsack_limitations(const std::vector<int> &w, const std::vector<T> &v, const std::vector<int> &m,  //
                                    const int W, const T &e, const F &comp = F(), const int s = 0) {
    const int n = (int)w.size();
    std::vector<T> dp(W + 1, e), deqv(W + 1);
    std::vector<int> deq(W + 1);
    dp[s] = T(0);
    for (int i = 0; i < n; i++) {
        if (w[i] > 0) {
            for (int a = 0; a < w[i]; a++) {
                int s = 0, t = 0;
                for (int j = 0; a + j * w[i] <= W; j++) {
                    if (dp[a + j * w[i]] != e) {
                        T val = dp[a + j * w[i]] - j * v[i];
                        while (s < t and comp(val, deqv[t - 1])) t--;
                        deq[t] = j;
                        deqv[t++] = val;
                    }
                    if (s < t) {
                        dp[a + j * w[i]] = deqv[s] + j * v[i];
                        if (deq[s] == j - m[i]) s++;
                    }
                }
            }
        } else if (w[i] < 0) {
            for (int a = 0; a < -w[i]; a++) {
                int s = 0, t = 0;
                for (int j = 0; W - a + j * w[i] >= 0; j++) {
                    if (dp[W - a + j * w[i]] != e) {
                        T val = dp[W - a + j * w[i]] - j * v[i];
                        while (s < t and comp(val, deqv[t - 1])) t--;
                        deq[t] = j;
                        deqv[t++] = val;
                    }
                    if (s < t) {
                        dp[W - a + j * w[i]] = deqv[s] + j * v[i];
                        if (deq[s] == j - m[i]) s++;
                    }
                }
            }
        } else {
            // w[i] = 0
            continue;
        }
    }
    return dp;
}