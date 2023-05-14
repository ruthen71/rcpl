---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: icpc/template.hpp
    title: icpc/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj_other/aoj_3326.test.cpp
    title: verify/aoj_other/aoj_3326.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/segtree.hpp\"\n\n#line 2 \"icpc/template.hpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n#define\
    \ REP(i, n) for (int i = 0; i < (n); i++)\ntemplate <class T> using V = vector<T>;\n\
    template <class T> ostream& operator<<(ostream &os, const V<T>& v) {\n    os <<\
    \ \"[ \";\n    for (auto &vi : v) os << vi << \", \";\n    return os << \"]\"\
    ;\n}\n\n#ifdef LOCAL\n#define show(x) cerr << __LINE__ << \" : \" << #x << \"\
    \ = \" << x << endl;\n#else\n#define show(x) true\n#endif\n\n// g++ -g -fsanitize=undefined,address\
    \ -DLOCAL -std=gnu++17\n#line 4 \"icpc/segtree.hpp\"\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct Segtree {\n    int n, size, log;\n    V<S> d;\n    Segtree()\
    \ : Segtree(0) {}\n    Segtree(int n) : Segtree(V<S>(n, e())) {}\n    Segtree(V<S>&\
    \ v) : n(int(v.size())) {\n        log = 0;\n        while ((1 << log) < n) log++;\n\
    \        size = 1 << log;\n        d = V<S>(size << 1, e());\n        REP(i, n)\
    \ d[i + size] = v[i];\n        for (int i = size - 1; i >= 1; i--) update(i);\n\
    \    }\n\n    void update(int k) { d[k] = op(d[k << 1], d[(k << 1) | 1]); }\n\n\
    \    void set(int p, const S& x) {\n        assert(0 <= p and p < n);\n      \
    \  p += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p and p < n);\n   \
    \     return d[p + size];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l and l <= r and r <= n);\n        S sml = e(), smr = e();\n        l +=\
    \ size, r += size;\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1,\
    \ r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ { return d[1]; }\n\n    template <class F> int max_right(int l, F f) {\n   \
    \     assert(0 <= l and l <= n);\n        assert(f(e()));\n        if (l == n)\
    \ return n;\n        l += size;\n        S sm = e();\n        do {\n         \
    \   while ((l & 1) == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n     \
    \           while (l < size) {\n                    l <<= 1;\n               \
    \     if (f(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n   \
    \                     l++;\n                    }\n                }\n       \
    \         return l - size;\n            }\n            sm = op(sm, d[l]);\n  \
    \          l++;\n        } while ((l & -l) != l);\n        return n;\n    }\n\n\
    \    template <class F> int min_left(int r, F& f) {\n        assert(0 <= r and\
    \ r <= n);\n        assert(f(e()));\n        if (r == 0) return 0;\n        r\
    \ += size;\n        S sm = e();\n        do {\n            r--;\n            while\
    \ (r > 1 and (r & 1)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n        \
    \        while (r < size) {\n                    r = (r << 1) | 1;\n         \
    \           if (f(op(d[r], sm))) {\n                        sm = op(d[r], sm);\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - size;\n            }\n            sm = op(d[r], sm);\n\
    \        } while ((r & -r) != r);\n        return 0;\n    }\n};\n"
  code: "#pragma once\n\n#include \"icpc/template.hpp\"\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct Segtree {\n    int n, size, log;\n    V<S> d;\n    Segtree()\
    \ : Segtree(0) {}\n    Segtree(int n) : Segtree(V<S>(n, e())) {}\n    Segtree(V<S>&\
    \ v) : n(int(v.size())) {\n        log = 0;\n        while ((1 << log) < n) log++;\n\
    \        size = 1 << log;\n        d = V<S>(size << 1, e());\n        REP(i, n)\
    \ d[i + size] = v[i];\n        for (int i = size - 1; i >= 1; i--) update(i);\n\
    \    }\n\n    void update(int k) { d[k] = op(d[k << 1], d[(k << 1) | 1]); }\n\n\
    \    void set(int p, const S& x) {\n        assert(0 <= p and p < n);\n      \
    \  p += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p and p < n);\n   \
    \     return d[p + size];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l and l <= r and r <= n);\n        S sml = e(), smr = e();\n        l +=\
    \ size, r += size;\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1,\
    \ r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ { return d[1]; }\n\n    template <class F> int max_right(int l, F f) {\n   \
    \     assert(0 <= l and l <= n);\n        assert(f(e()));\n        if (l == n)\
    \ return n;\n        l += size;\n        S sm = e();\n        do {\n         \
    \   while ((l & 1) == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n     \
    \           while (l < size) {\n                    l <<= 1;\n               \
    \     if (f(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n   \
    \                     l++;\n                    }\n                }\n       \
    \         return l - size;\n            }\n            sm = op(sm, d[l]);\n  \
    \          l++;\n        } while ((l & -l) != l);\n        return n;\n    }\n\n\
    \    template <class F> int min_left(int r, F& f) {\n        assert(0 <= r and\
    \ r <= n);\n        assert(f(e()));\n        if (r == 0) return 0;\n        r\
    \ += size;\n        S sm = e();\n        do {\n            r--;\n            while\
    \ (r > 1 and (r & 1)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n        \
    \        while (r < size) {\n                    r = (r << 1) | 1;\n         \
    \           if (f(op(d[r], sm))) {\n                        sm = op(d[r], sm);\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - size;\n            }\n            sm = op(d[r], sm);\n\
    \        } while ((r & -r) != r);\n        return 0;\n    }\n};"
  dependsOn:
  - icpc/template.hpp
  isVerificationFile: false
  path: icpc/segtree.hpp
  requiredBy: []
  timestamp: '2023-05-15 01:12:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj_other/aoj_3326.test.cpp
documentation_of: icpc/segtree.hpp
layout: document
redirect_from:
- /library/icpc/segtree.hpp
- /library/icpc/segtree.hpp.html
title: icpc/segtree.hpp
---
