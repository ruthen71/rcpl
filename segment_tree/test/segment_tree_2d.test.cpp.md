---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_min.hpp
    title: algebra/monoid/monoid_min.hpp
  - icon: ':heavy_check_mark:'
    path: misc/bit_ceil.hpp
    title: Bit Ceil
  - icon: ':heavy_check_mark:'
    path: misc/countr_zero.hpp
    title: Countr Zero
  - icon: ':heavy_check_mark:'
    path: segment_tree/segment_tree_2d.hpp
    title: "2D Segment Tree (2 \u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068
  bundledCode: "#line 1 \"segment_tree/test/segment_tree_2d.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068\"\n\n#include\
    \ <iostream>\n#include <limits>\n\n#line 2 \"algebra/monoid/monoid_min.hpp\"\n\
    \ntemplate <class T, T inf> struct MonoidMin {\n    using value_type = T;\n  \
    \  static constexpr T operation(const T& a, const T& b) noexcept {\n        return\
    \ std::min(a, b);\n    }\n    static constexpr T identity() noexcept { return\
    \ inf; }\n    static constexpr bool commutative = true;\n};\n#line 2 \"segment_tree/segment_tree_2d.hpp\"\
    \n\n#line 2 \"misc/bit_ceil.hpp\"\n\n#include <cassert>\n\n#if __cplusplus >=\
    \ 202002L\n#include <bit>\n#endif\n\n// bit_ceil\n// (0, 1, 2, 3, 4) -> (1, 1,\
    \ 2, 4, 4)\n#if __cplusplus >= 202002L\nusing std::bit_ceil;\n#else\nunsigned\
    \ int bit_ceil(unsigned int x) {\n    unsigned int p = 1;\n    while (p < x) p\
    \ *= 2;\n    return p;\n}\nunsigned long long int bit_ceil(unsigned long long\
    \ int x) {\n    unsigned long long int p = 1;\n    while (p < x) p *= 2;\n   \
    \ return p;\n}\n#endif\nint bit_ceil(int x) {\n    assert(x >= 0);\n    return\
    \ bit_ceil((unsigned int)(x));\n}\nlong long int bit_ceil(long long int x) {\n\
    \    assert(x >= 0);\n    return bit_ceil((unsigned long long int)(x));\n}\n#line\
    \ 2 \"misc/countr_zero.hpp\"\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\
    \n// countr_zero\n// (000, 001, 010, 011, 100) -> (32, 0, 1, 0, 2)\n#if __cplusplus\
    \ >= 202002L\nusing std::countr_zero;\n#else\nint countr_zero(unsigned int x)\
    \ {\n    return x == 0 ? 32 : __builtin_ctz(x);\n}\nint countr_zero(unsigned long\
    \ long int x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n}\n#endif\nint\
    \ countr_zero(int x) { return countr_zero((unsigned int)(x)); }\nint countr_zero(long\
    \ long int x) {\n    return countr_zero((unsigned long long int)(x));\n}\n#line\
    \ 5 \"segment_tree/segment_tree_2d.hpp\"\n\n#line 7 \"segment_tree/segment_tree_2d.hpp\"\
    \n#include <vector>\n\n// Segment Tree 2D\ntemplate <class MS> struct SegmentTree2D\
    \ {\n  public:\n    using S = typename MS::value_type;\n\n    SegmentTree2D()\
    \ = default;\n\n    explicit SegmentTree2D(int h, int w)\n        : SegmentTree2D(std::vector(h,\
    \ std::vector<S>(w, MS::identity()))) {}\n\n    explicit SegmentTree2D(const std::vector<std::vector<S>>&\
    \ v)\n        : h((int)(v.size())), w((int)(v[0].size())) {\n        sizeh = bit_ceil(h);\n\
    \        logh = countr_zero(sizeh);\n        sizew = bit_ceil(w);\n        logw\
    \ = countr_zero(sizew);\n        d = std::vector(sizeh << 1, std::vector<S>(sizew\
    \ << 1, MS::identity()));\n        for (int i = 0; i < h; i++) {\n           \
    \ for (int j = 0; j < w; j++) {\n                d[i + sizeh][j + sizew] = v[i][j];\n\
    \            }\n        }\n        for (int i = sizeh - 1; i >= 1; i--) {\n  \
    \          for (int j = sizew; j < (sizew << 1); j++) {\n                update_bottom(i,\
    \ j);\n            }\n        }\n        for (int i = 0; i < (sizeh << 1); i++)\
    \ {\n            for (int j = sizew - 1; j >= 1; j--) {\n                update_else(i,\
    \ j);\n            }\n        }\n    }\n\n    void set(int h, int w, const S&\
    \ x) {\n        assert(0 <= h and h < h and 0 <= w and w < w);\n        h += sizeh;\n\
    \        w += sizew;\n        d[h][w] = x;\n        for (int i = 1; i <= logh;\
    \ i++) update_bottom(h >> i, w);\n        for (int i = 0; i <= logh; i++) {\n\
    \            for (int j = 1; j <= logw; j++) {\n                update_else(h\
    \ >> i, w >> j);\n            }\n        }\n    }\n\n    void add(int h, int w,\
    \ const S& x) {\n        assert(0 <= h and h < h and 0 <= w and w < w);\n    \
    \    h += sizeh;\n        w += sizew;\n        d[h][w] = MS::operation(d[h][w],\
    \ x);\n        for (int i = 1; i <= logh; i++) update_bottom(h >> i, w);\n   \
    \     for (int i = 0; i <= logh; i++) {\n            for (int j = 1; j <= logw;\
    \ j++) {\n                update_else(h >> i, w >> j);\n            }\n      \
    \  }\n    }\n\n    S operator()(int h, int w) const {\n        assert(0 <= h and\
    \ h < h and 0 <= w and w < w);\n        return d[h + sizeh][w + sizew];\n    }\n\
    \n    S get(int h, int w) const {\n        assert(0 <= h and h < h and 0 <= w\
    \ and w < w);\n        return d[h + sizeh][w + sizew];\n    }\n\n    S inner_prod(int\
    \ h, int w1, int w2) {\n        S sml = MS::identity(), smr = MS::identity();\n\
    \        while (w1 < w2) {\n            if (w1 & 1) sml = MS::operation(sml, d[h][w1++]);\n\
    \            if (w2 & 1) smr = MS::operation(d[h][--w2], smr);\n            w1\
    \ >>= 1;\n            w2 >>= 1;\n        }\n        return MS::operation(sml,\
    \ smr);\n    }\n\n    S prod(int h1, int w1, int h2, int w2) {\n        assert(0\
    \ <= h1 and h1 <= h2 and h2 <= h);\n        assert(0 <= w1 and w1 <= w2 and w2\
    \ <= w);\n        S sml = MS::identity(), smr = MS::identity();\n        h1 +=\
    \ sizeh;\n        h2 += sizeh;\n        w1 += sizew;\n        w2 += sizew;\n\n\
    \        while (h1 < h2) {\n            if (h1 & 1) sml = MS::operation(sml, inner_prod(h1++,\
    \ w1, w2));\n            if (h2 & 1) smr = MS::operation(inner_prod(--h2, w1,\
    \ w2), smr);\n            h1 >>= 1;\n            h2 >>= 1;\n        }\n      \
    \  return MS::operation(sml, smr);\n    }\n\n    S all_prod() const { return d[1][1];\
    \ }\n\n    std::vector<std::vector<S>> make_vector() {\n        std::vector vec(h,\
    \ std::vector<S>(w));\n        for (int i = 0; i < h; i++) {\n            for\
    \ (int j = 0; j < w; j++) vec[i][j] = get(i, j);\n        }\n        return vec;\n\
    \    }\n\n  private:\n    int h, logh, sizeh, w, logw, sizew;\n    std::vector<std::vector<S>>\
    \ d;\n\n    inline void update_bottom(int i, int j) {\n        d[i][j] = MS::operation(d[(i\
    \ << 1) | 0][j], d[(i << 1) | 1][j]);\n    }\n\n    inline void update_else(int\
    \ i, int j) {\n        d[i][j] = MS::operation(d[i][(j << 1) | 0], d[i][(j <<\
    \ 1) | 1]);\n    }\n};\n#line 8 \"segment_tree/test/segment_tree_2d.test.cpp\"\
    \n\nvoid solve(int R, int C, int Q) {\n    std::vector<std::vector<int>> A(R,\
    \ std::vector<int>(C));\n    for (int i = 0; i < R; i++) {\n        for (int j\
    \ = 0; j < C; j++) {\n            std::cin >> A[i][j];\n        }\n    }\n   \
    \ constexpr int INF = std::numeric_limits<int>::max();\n    SegmentTree2D<MonoidMin<int,\
    \ INF>> seg(A);\n    while (Q--) {\n        int r1, c1, r2, c2;\n        std::cin\
    \ >> r1 >> c1 >> r2 >> c2;\n        std::cout << seg.prod(r1, c1, r2 + 1, c2 +\
    \ 1) << '\\n';\n    }\n    return;\n}\n\nint main() {\n    int R, C, Q;\n    while\
    \ (std::cin >> R >> C >> Q, !(R == 0 and C == 0 and Q == 0))\n        solve(R,\
    \ C, Q);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068\"\
    \n\n#include <iostream>\n#include <limits>\n\n#include \"../../algebra/monoid/monoid_min.hpp\"\
    \n#include \"../../segment_tree/segment_tree_2d.hpp\"\n\nvoid solve(int R, int\
    \ C, int Q) {\n    std::vector<std::vector<int>> A(R, std::vector<int>(C));\n\
    \    for (int i = 0; i < R; i++) {\n        for (int j = 0; j < C; j++) {\n  \
    \          std::cin >> A[i][j];\n        }\n    }\n    constexpr int INF = std::numeric_limits<int>::max();\n\
    \    SegmentTree2D<MonoidMin<int, INF>> seg(A);\n    while (Q--) {\n        int\
    \ r1, c1, r2, c2;\n        std::cin >> r1 >> c1 >> r2 >> c2;\n        std::cout\
    \ << seg.prod(r1, c1, r2 + 1, c2 + 1) << '\\n';\n    }\n    return;\n}\n\nint\
    \ main() {\n    int R, C, Q;\n    while (std::cin >> R >> C >> Q, !(R == 0 and\
    \ C == 0 and Q == 0))\n        solve(R, C, Q);\n    return 0;\n}\n"
  dependsOn:
  - algebra/monoid/monoid_min.hpp
  - segment_tree/segment_tree_2d.hpp
  - misc/bit_ceil.hpp
  - misc/countr_zero.hpp
  isVerificationFile: true
  path: segment_tree/test/segment_tree_2d.test.cpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: segment_tree/test/segment_tree_2d.test.cpp
layout: document
redirect_from:
- /verify/segment_tree/test/segment_tree_2d.test.cpp
- /verify/segment_tree/test/segment_tree_2d.test.cpp.html
title: segment_tree/test/segment_tree_2d.test.cpp
---
