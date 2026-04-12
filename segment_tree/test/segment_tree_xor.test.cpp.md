---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_xor.hpp
    title: algebra/monoid/monoid_xor.hpp
  - icon: ':heavy_check_mark:'
    path: misc/bit_ceil.hpp
    title: Bit Ceil
  - icon: ':heavy_check_mark:'
    path: misc/countr_zero.hpp
    title: Countr Zero
  - icon: ':heavy_check_mark:'
    path: segment_tree/segment_tree.hpp
    title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"segment_tree/test/segment_tree_xor.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\n#line 2\
    \ \"algebra/monoid/monoid_xor.hpp\"\n\ntemplate <class T> struct MonoidXor {\n\
    \    using value_type = T;\n    static constexpr T operation(const T& a, const\
    \ T& b) noexcept {\n        return a ^ b;\n    }\n    static constexpr T identity()\
    \ noexcept { return T(0); }\n    static constexpr T inverse(const T& a) noexcept\
    \ { return a; }\n    static constexpr bool commutative = true;\n};\n#line 2 \"\
    segment_tree/segment_tree.hpp\"\n\n#line 2 \"misc/bit_ceil.hpp\"\n\n#include <cassert>\n\
    \n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n// bit_ceil\n// (0, 1,\
    \ 2, 3, 4) -> (1, 1, 2, 4, 4)\n#if __cplusplus >= 202002L\nusing std::bit_ceil;\n\
    #else\nunsigned int bit_ceil(unsigned int x) {\n    unsigned int p = 1;\n    while\
    \ (p < x) p *= 2;\n    return p;\n}\nunsigned long long int bit_ceil(unsigned\
    \ long long int x) {\n    unsigned long long int p = 1;\n    while (p < x) p *=\
    \ 2;\n    return p;\n}\n#endif\nint bit_ceil(int x) {\n    assert(x >= 0);\n \
    \   return bit_ceil((unsigned int)(x));\n}\nlong long int bit_ceil(long long int\
    \ x) {\n    assert(x >= 0);\n    return bit_ceil((unsigned long long int)(x));\n\
    }\n#line 2 \"misc/countr_zero.hpp\"\n\n#if __cplusplus >= 202002L\n#include <bit>\n\
    #endif\n\n// countr_zero\n// (000, 001, 010, 011, 100) -> (32, 0, 1, 0, 2)\n#if\
    \ __cplusplus >= 202002L\nusing std::countr_zero;\n#else\nint countr_zero(unsigned\
    \ int x) {\n    return x == 0 ? 32 : __builtin_ctz(x);\n}\nint countr_zero(unsigned\
    \ long long int x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n}\n#endif\n\
    int countr_zero(int x) { return countr_zero((unsigned int)(x)); }\nint countr_zero(long\
    \ long int x) {\n    return countr_zero((unsigned long long int)(x));\n}\n#line\
    \ 5 \"segment_tree/segment_tree.hpp\"\n\n#line 7 \"segment_tree/segment_tree.hpp\"\
    \n#include <vector>\n\n// Segment Tree\ntemplate <class MS> struct SegmentTree\
    \ {\n  public:\n    using S = typename MS::value_type;\n\n    SegmentTree() =\
    \ default;\n\n    explicit SegmentTree(int n)\n        : SegmentTree(std::vector<S>(n,\
    \ MS::identity())) {}\n\n    explicit SegmentTree(const std::vector<S>& v) : n((int)(v.size()))\
    \ {\n        size = bit_ceil(n);\n        log = countr_zero(size);\n        d\
    \ = std::vector<S>(size << 1, MS::identity());\n        for (int i = 0; i < n;\
    \ i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n  \
    \          update(i);\n        }\n    }\n\n    void set(int p, const S& x) {\n\
    \        assert(0 <= p and p < n);\n        p += size;\n        d[p] = x;\n  \
    \      for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void add(int\
    \ p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n  \
    \      d[p] = MS::operation(d[p], x);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S operator[](int p) const {\n        assert(0\
    \ <= p and p < n);\n        return d[p + size];\n    }\n\n    S get(int p) const\
    \ {\n        assert(0 <= p && p < n);\n        return d[p + size];\n    }\n\n\
    \    S prod(int l, int r) const {\n        assert(0 <= l and l <= r and r <= n);\n\
    \        S sml = MS::identity(), smr = MS::identity();\n        l += size;\n \
    \       r += size;\n\n        while (l < r) {\n            if (l & 1) sml = MS::operation(sml,\
    \ d[l++]);\n            if (r & 1) smr = MS::operation(d[--r], smr);\n       \
    \     l >>= 1;\n            r >>= 1;\n        }\n        return MS::operation(sml,\
    \ smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n    template <class\
    \ G> int max_right(int l, G& g) const {\n        assert(0 <= l and l <= n);\n\
    \        assert(g(MS::identity()));\n        if (l == n) return n;\n        l\
    \ += size;\n        S sm = MS::identity();\n        do {\n            while ((l\
    \ & 1) == 0) l >>= 1;\n            if (!g(MS::operation(sm, d[l]))) {\n      \
    \          while (l < size) {\n                    l <<= 1;\n                \
    \    if (g(MS::operation(sm, d[l]))) {\n                        sm = MS::operation(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - size;\n            }\n            sm = MS::operation(sm,\
    \ d[l]);\n            l++;\n        } while ((l & -l) != l);\n        return n;\n\
    \    }\n\n    template <class G> int min_left(int r, G& g) const {\n        assert(0\
    \ <= r and r <= n);\n        assert(g(MS::identity()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        S sm = MS::identity();\n        do {\n     \
    \       r--;\n            while (r > 1 and (r & 1)) r >>= 1;\n            if (!g(MS::operation(d[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (r << 1)\
    \ | 1;\n                    if (g(MS::operation(d[r], sm))) {\n              \
    \          sm = MS::operation(d[r], sm);\n                        r--;\n     \
    \               }\n                }\n                return r + 1 - size;\n \
    \           }\n            sm = MS::operation(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n    std::vector<S> make_vector() const\
    \ {\n        std::vector<S> vec(n);\n        for (int i = 0; i < n; i++) vec[i]\
    \ = get(i);\n        return vec;\n    }\n\n  private:\n    int n, log, size;\n\
    \    std::vector<S> d;\n\n    inline void update(int k) {\n        d[k] = MS::operation(d[k\
    \ << 1], d[(k << 1) | 1]);\n    }\n};\n#line 7 \"segment_tree/test/segment_tree_xor.test.cpp\"\
    \n\nvoid test1_basic() {\n    assert(MonoidXor<int>::commutative == true);\n \
    \   assert(MonoidXor<int>::identity() == 0);\n}\n\nvoid test2_sequence() {\n \
    \   std::vector<int> a = {3, 1, 4, 1, 5};\n    SegmentTree<MonoidXor<int>> seg(a);\n\
    \    assert(seg.prod(0, 0) == 0);\n    assert(seg.prod(0, 2) == (a[0] ^ a[1]));\n\
    \    assert(seg.prod(1, 3) == (a[1] ^ a[2]));\n    assert(seg.prod(2, 4) == (a[2]\
    \ ^ a[3]));\n    assert(seg.prod(3, 5) == (a[3] ^ a[4]));\n    assert(seg.prod(0,\
    \ 5) == (a[0] ^ a[1] ^ a[2] ^ a[3] ^ a[4]));\n}\n\nint main() {\n    test1_basic();\n\
    \    test2_sequence();\n    int a, b;\n    std::cin >> a >> b;\n    std::cout\
    \ << a + b << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\
    \n#include \"../../algebra/monoid/monoid_xor.hpp\"\n#include \"../../segment_tree/segment_tree.hpp\"\
    \n\nvoid test1_basic() {\n    assert(MonoidXor<int>::commutative == true);\n \
    \   assert(MonoidXor<int>::identity() == 0);\n}\n\nvoid test2_sequence() {\n \
    \   std::vector<int> a = {3, 1, 4, 1, 5};\n    SegmentTree<MonoidXor<int>> seg(a);\n\
    \    assert(seg.prod(0, 0) == 0);\n    assert(seg.prod(0, 2) == (a[0] ^ a[1]));\n\
    \    assert(seg.prod(1, 3) == (a[1] ^ a[2]));\n    assert(seg.prod(2, 4) == (a[2]\
    \ ^ a[3]));\n    assert(seg.prod(3, 5) == (a[3] ^ a[4]));\n    assert(seg.prod(0,\
    \ 5) == (a[0] ^ a[1] ^ a[2] ^ a[3] ^ a[4]));\n}\n\nint main() {\n    test1_basic();\n\
    \    test2_sequence();\n    int a, b;\n    std::cin >> a >> b;\n    std::cout\
    \ << a + b << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - algebra/monoid/monoid_xor.hpp
  - segment_tree/segment_tree.hpp
  - misc/bit_ceil.hpp
  - misc/countr_zero.hpp
  isVerificationFile: true
  path: segment_tree/test/segment_tree_xor.test.cpp
  requiredBy: []
  timestamp: '2026-04-12 20:46:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: segment_tree/test/segment_tree_xor.test.cpp
layout: document
redirect_from:
- /verify/segment_tree/test/segment_tree_xor.test.cpp
- /verify/segment_tree/test/segment_tree_xor.test.cpp.html
title: segment_tree/test/segment_tree_xor.test.cpp
---
