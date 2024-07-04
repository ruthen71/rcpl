---
title: Longest Increasing Subsequence (最長増加部分列)
documentation_of: //dp/longest_increasing_subsequence.hpp
---

`dp[i] = 長さ i + 1 の LIS の末尾の最小値` として求める

`strict = true` では狭義単調増加列を、`strict = false` では広義単調増加列を求める
