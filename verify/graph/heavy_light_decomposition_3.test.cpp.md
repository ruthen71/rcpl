---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s/monoid_sum.hpp
    title: algebra/monoid_s/monoid_sum.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/heavy_light_decomposition.hpp
    title: "Heavy-Light Decomposition (\u91CD\u8EFD\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: graph/read_graph.hpp
    title: "\u30B0\u30E9\u30D5\u5165\u529B\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"verify/graph/heavy_light_decomposition_3.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#include\
    \ <iostream>\n\n#line 2 \"my_template.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <complex>\n#include <deque>\n#include <forward_list>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#include <ios>\n#line 16 \"my_template.hpp\"\
    \n#include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <numeric>\n#include <optional>\n#include <queue>\n#include <random>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <utility>\n#include <vector>\n\n#ifdef RUTHEN_LOCAL\n#include <debug.hpp>\n\
    #else\n#define show(x) true\n#endif\n\n// type definition\nusing i64 = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing f32 = float;\n\
    using f64 = double;\nusing f128 = long double;\ntemplate <class T> using pque\
    \ = std::priority_queue<T>;\ntemplate <class T> using pqueg = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n// overload\n#define overload4(_1, _2, _3,\
    \ _4, name, ...) name\n#define overload3(_1, _2, _3, name, ...) name\n#define\
    \ overload2(_1, _2, name, ...) name\n// for loop\n#define REP1(a) for (long long\
    \ _ = 0; _ < (a); _++)\n#define REP2(i, a) for (long long i = 0; i < (a); i++)\n\
    #define REP3(i, a, b) for (long long i = (a); i < (b); i++)\n#define REP4(i, a,\
    \ b, c) for (long long i = (a); i < (b); i += (c))\n#define REP(...) overload4(__VA_ARGS__,\
    \ REP4, REP3, REP2, REP1)(__VA_ARGS__)\n#define RREP1(a) for (long long _ = (a)-1;\
    \ _ >= 0; _--)\n#define RREP2(i, a) for (long long i = (a)-1; i >= 0; i--)\n#define\
    \ RREP3(i, a, b) for (long long i = (b)-1; i >= (a); i--)\n#define RREP(...) overload3(__VA_ARGS__,\
    \ RREP3, RREP2, RREP1)(__VA_ARGS__)\n#define FORE1(x, a) for (auto&& x : a)\n\
    #define FORE2(x, y, a) for (auto&& [x, y] : a)\n#define FORE3(x, y, z, a) for\
    \ (auto&& [x, y, z] : a)\n#define FORE(...) overload4(__VA_ARGS__, FORE3, FORE2,\
    \ FORE1)(__VA_ARGS__)\n#define FORSUB(t, s) for (long long t = (s); t >= 0; t\
    \ = (t == 0 ? -1 : (t - 1) & (s)))\n// function\n#define ALL(a) (a).begin(), (a).end()\n\
    #define RALL(a) (a).rbegin(), (a).rend()\n#define SORT(a) std::sort((a).begin(),\
    \ (a).end())\n#define RSORT(a) std::sort((a).rbegin(), (a).rend())\n#define REV(a)\
    \ std::reverse((a).begin(), (a).end())\n#define UNIQUE(a)                    \
    \  \\\n    std::sort((a).begin(), (a).end()); \\\n    (a).erase(std::unique((a).begin(),\
    \ (a).end()), (a).end())\n#define LEN(a) (int)((a).size())\n#define MIN(a) *std::min_element((a).begin(),\
    \ (a).end())\n#define MAX(a) *std::max_element((a).begin(), (a).end())\n#define\
    \ SUM1(a) std::accumulate((a).begin(), (a).end(), 0LL)\n#define SUM2(a, x) std::accumulate((a).begin(),\
    \ (a).end(), (x))\n#define SUM(...) overload2(__VA_ARGS__, SUM2, SUM1)(__VA_ARGS__)\n\
    #define LB(a, x) std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(),\
    \ (x)))\n#define UB(a, x) std::distance((a).begin(), std::upper_bound((a).begin(),\
    \ (a).end(), (x)))\ntemplate <class T, class U> inline bool chmin(T& a, const\
    \ U& b) { return (a > T(b) ? a = b, 1 : 0); }\ntemplate <class T, class U> inline\
    \ bool chmax(T& a, const U& b) { return (a < T(b) ? a = b, 1 : 0); }\ntemplate\
    \ <class T, class S> inline T floor(const T x, const S y) {\n    assert(y);\n\
    \    return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : x / y - (x % y == 0 ? 0\
    \ : 1)));\n}\ntemplate <class T, class S> inline T ceil(const T x, const S y)\
    \ {\n    assert(y);\n    return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) /\
    \ y : x / y));\n}\ntemplate <class T, class S> std::pair<T, T> inline divmod(const\
    \ T x, const S y) {\n    T q = floor(x, y);\n    return {q, x - q * y};\n}\n//\
    \ 10 ^ n\nconstexpr long long TEN(int n) { return (n == 0) ? 1 : 10LL * TEN(n\
    \ - 1); }\n// 1 + 2 + ... + n\n#define TRI1(n) ((n) * ((n) + 1LL) / 2)\n// l +\
    \ (l + 1) + ... + r\n#define TRI2(l, r) (((l) + (r)) * ((r) - (l) + 1LL) / 2)\n\
    #define TRI(...) overload2(__VA_ARGS__, TRI2, TRI1)(__VA_ARGS__)\n// bit operation\n\
    // bit[i] (= 0 or 1)\n#define IBIT(bit, i) (((bit) >> (i)) & 1)\n// (0, 1, 2,\
    \ 3, 4) -> (0, 1, 3, 7, 15)\n#define MASK(n) ((1LL << (n)) - 1)\n#define POW2(n)\
    \ (1LL << (n))\n// (0, 1, 2, 3, 4) -> (0, 1, 1, 2, 1)\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(i64 x) { return __builtin_popcountll(x); }\nint popcnt(u64 x)\
    \ { return __builtin_popcountll(x); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\n\
    int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32\
    \ x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(i64 x) { return\
    \ (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x ==\
    \ 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\n\
    int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(u32\
    \ x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(i64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return (x == 0 ?\
    \ -1 : __builtin_ctzll(x)); }\n// binary search (integer)\ntemplate <class T,\
    \ class F> T bin_search(T ok, T ng, F& f) {\n    while ((ok > ng ? ok - ng : ng\
    \ - ok) > 1) {\n        T md = (ng + ok) >> 1;\n        (f(md) ? ok : ng) = md;\n\
    \    }\n    return ok;\n}\n// binary search (real number)\ntemplate <class T,\
    \ class F> T bin_search_real(T ok, T ng, F& f, const int iter = 100) {\n    for\
    \ (int _ = 0; _ < iter; _++) {\n        T md = (ng + ok) / 2;\n        (f(md)\
    \ ? ok : ng) = md;\n    }\n    return ok;\n}\n// floor(sqrt(x))\ntemplate <class\
    \ T> T sqrt_floor(T x) { return T(sqrtl(x)); }\n// check if [l1, r1) and [l2,\
    \ r2) intersect\ntemplate <class T> bool intersect(const T l1, const T r1, const\
    \ T l2, const T r2) { return std::max(l1, l2) < std::min(r1, r2); }\n// check\
    \ if [a.first, a.second) and [b.first, b.second) intersect\ntemplate <class T>\
    \ bool intersect(const std::pair<T, T>& a, const std::pair<T, T>& b) { return\
    \ intersect(a.first, a.second, b.first, b.second); }\n// rotate matrix counterclockwise\
    \ by pi / 2\ntemplate <class T> void rot(std::vector<std::vector<T>>& a) {\n \
    \   if ((int)(a.size()) == 0) return;\n    if ((int)(a[0].size()) == 0) return;\n\
    \    int n = (int)(a.size()), m = (int)(a[0].size());\n    std::vector res(m,\
    \ std::vector<T>(n));\n    for (int i = 0; i < n; i++) {\n        for (int j =\
    \ 0; j < m; j++) {\n            res[m - 1 - j][i] = a[i][j];\n        }\n    }\n\
    \    a.swap(res);\n}\n// const value\nconstexpr int dx[8] = {1, 0, -1, 0, 1, -1,\
    \ -1, 1};\nconstexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\n// infinity\ntemplate\
    \ <class T> constexpr T INF = 0;\ntemplate <> constexpr int INF<int> = 1'000'000'000;\
    \                 // 1e9\ntemplate <> constexpr i64 INF<i64> = i64(INF<int>) *\
    \ INF<int> * 2;  // 2e18\ntemplate <> constexpr u32 INF<u32> = INF<int>;     \
    \                 // 1e9\ntemplate <> constexpr u64 INF<u64> = INF<i64>;     \
    \                 // 2e18\ntemplate <> constexpr f32 INF<f32> = INF<i64>;    \
    \                  // 2e18\ntemplate <> constexpr f64 INF<f64> = INF<i64>;   \
    \                   // 2e18\ntemplate <> constexpr f128 INF<f128> = INF<i64>;\
    \                    // 2e18\n// I/O\n// input\ntemplate <class T> std::istream&\
    \ operator>>(std::istream& is, std::vector<T>& v) {\n    for (auto&& i : v) is\
    \ >> i;\n    return is;\n}\ntemplate <class... T> void in(T&... a) { (std::cin\
    \ >> ... >> a); }\nvoid scan() {}\ntemplate <class Head, class... Tail> void scan(Head&\
    \ head, Tail&... tail) {\n    in(head);\n    scan(tail...);\n}\n// input macro\n\
    #define INT(...)     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ I64(...)     \\\n    i64 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define U32(...)\
    \     \\\n    u32 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define U64(...)   \
    \  \\\n    u64 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define F32(...)     \\\
    \n    f32 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define F64(...)     \\\n  \
    \  f64 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define F128(...)     \\\n    f128\
    \ __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define STR(...)             \\\n  \
    \  std::string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define CHR(...)      \\\
    \n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define VEC(type, name, size)\
    \     \\\n    std::vector<type> name(size); \\\n    scan(name)\n#define VEC2(type,\
    \ name1, name2, size)          \\\n    std::vector<type> name1(size), name2(size);\
    \ \\\n    for (int i = 0; i < size; i++) scan(name1[i], name2[i])\n#define VEC3(type,\
    \ name1, name2, name3, size)                \\\n    std::vector<type> name1(size),\
    \ name2(size), name3(size); \\\n    for (int i = 0; i < size; i++) scan(name1[i],\
    \ name2[i], name3[i])\n#define VEC4(type, name1, name2, name3, name4, size)  \
    \                    \\\n    std::vector<type> name1(size), name2(size), name3(size),\
    \ name4(size); \\\n    for (int i = 0; i < size; i++) scan(name1[i], name2[i],\
    \ name3[i], name4[i])\n#define VV(type, name, h, w)                       \\\n\
    \    std::vector name((h), std::vector<type>((w))); \\\n    scan(name)\n// output\n\
    template <class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>&\
    \ v) {\n    auto n = v.size();\n    for (size_t i = 0; i < n; i++) {\n       \
    \ if (i) os << ' ';\n        os << v[i];\n    }\n    return os;\n}\ntemplate <class...\
    \ T> void out(const T&... a) { (std::cout << ... << a); }\nvoid print() { out('\\\
    n'); }\ntemplate <class Head, class... Tail> void print(Head&& head, Tail&&...\
    \ tail) {\n    out(head);\n    if (sizeof...(Tail)) out(' ');\n    print(tail...);\n\
    }\n// for interactive problems\nvoid printi() { std::cout << std::endl; }\ntemplate\
    \ <class Head, class... Tail> void printi(Head&& head, Tail&&... tail) {\n   \
    \ out(head);\n    if (sizeof...(Tail)) out(' ');\n    printi(tail...);\n}\n//\
    \ bool output\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\nvoid Yes(bool\
    \ t = 1) { print(t ? \"Yes\" : \"No\"); }\nvoid yes(bool t = 1) { print(t ? \"\
    yes\" : \"no\"); }\nvoid NO(bool t = 1) { YES(!t); }\nvoid No(bool t = 1) { Yes(!t);\
    \ }\nvoid no(bool t = 1) { yes(!t); }\nvoid POSSIBLE(bool t = 1) { print(t ? \"\
    POSSIBLE\" : \"IMPOSSIBLE\"); }\nvoid Possible(bool t = 1) { print(t ? \"Possible\"\
    \ : \"Impossible\"); }\nvoid possible(bool t = 1) { print(t ? \"possible\" : \"\
    impossible\"); }\nvoid IMPOSSIBLE(bool t = 1) { POSSIBLE(!t); }\nvoid Impossible(bool\
    \ t = 1) { Possible(!t); }\nvoid impossible(bool t = 1) { possible(!t); }\nvoid\
    \ FIRST(bool t = 1) { print(t ? \"FIRST\" : \"SECOND\"); }\nvoid First(bool t\
    \ = 1) { print(t ? \"First\" : \"Second\"); }\nvoid first(bool t = 1) { print(t\
    \ ? \"first\" : \"second\"); }\nvoid SECOND(bool t = 1) { FIRST(!t); }\nvoid Second(bool\
    \ t = 1) { First(!t); }\nvoid second(bool t = 1) { first(!t); }\n// I/O speed\
    \ up\nstruct SetUpIO {\n    SetUpIO() {\n        std::ios::sync_with_stdio(false);\n\
    \        std::cin.tie(0);\n        std::cout << std::fixed << std::setprecision(15);\n\
    \    }\n} set_up_io;\n#line 2 \"graph/read_graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#line 5 \"graph/graph_template.hpp\"\n\ntemplate <class T> struct Edge {\n\
    \    int from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(const\
    \ int from, const int to, const T cost = T(1), const int id = -1) : from(from),\
    \ to(to), cost(cost), id(id) {}\n\n    friend bool operator<(const Edge<T>& a,\
    \ const Edge<T>& b) { return a.cost < b.cost; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Edge<T>& e) {\n        // output format: {id: cost(from, to) = cost}\n\
    \        return os << \"{\" << e.id << \": cost(\" << e.from << \", \" << e.to\
    \ << \") = \" << e.cost << \"}\";\n    }\n};\ntemplate <class T> using Edges =\
    \ std::vector<Edge<T>>;\n\ntemplate <class T> struct Graph {\n    struct EdgeIterators\
    \ {\n       public:\n        using Iterator = typename std::vector<Edge<T>>::iterator;\n\
    \        EdgeIterators() = default;\n        EdgeIterators(const Iterator& begit,\
    \ const Iterator& endit) : begit(begit), endit(endit) {}\n        Iterator begin()\
    \ const { return begit; }\n        Iterator end() const { return endit; }\n  \
    \      size_t size() const { return std::distance(begit, endit); }\n        Edge<T>&\
    \ operator[](int i) const { return begit[i]; }\n\n       private:\n        Iterator\
    \ begit, endit;\n    };\n\n    int n, m;\n    bool is_build, is_directed;\n  \
    \  std::vector<Edge<T>> edges;\n\n    // CSR (Compressed Row Storage) \u5F62\u5F0F\
    \u7528\n    std::vector<int> start;\n    std::vector<Edge<T>> csr_edges;\n\n \
    \   Graph() = default;\n    Graph(const int n, const bool directed = false) :\
    \ n(n), m(0), is_build(false), is_directed(directed), start(n + 1, 0) {}\n\n \
    \   // \u8FBA\u3092\u8FFD\u52A0\u3057, \u305D\u306E\u8FBA\u304C\u4F55\u756A\u76EE\
    \u306B\u8FFD\u52A0\u3055\u308C\u305F\u304B\u3092\u8FD4\u3059\n    int add_edge(const\
    \ int from, const int to, const T cost = T(1), int id = -1) {\n        assert(!is_build);\n\
    \        assert(0 <= from and from < n);\n        assert(0 <= to and to < n);\n\
    \        if (id == -1) id = m;\n        edges.emplace_back(from, to, cost, id);\n\
    \        return m++;\n    }\n\n    // CSR \u5F62\u5F0F\u3067\u30B0\u30E9\u30D5\
    \u3092\u69CB\u7BC9\n    void build() {\n        assert(!is_build);\n        for\
    \ (auto&& e : edges) {\n            start[e.from + 1]++;\n            if (!is_directed)\
    \ start[e.to + 1]++;\n        }\n        for (int v = 0; v < n; v++) start[v +\
    \ 1] += start[v];\n        auto counter = start;\n        csr_edges.resize(start.back()\
    \ + 1);\n        for (auto&& e : edges) {\n            csr_edges[counter[e.from]++]\
    \ = e;\n            if (!is_directed) csr_edges[counter[e.to]++] = Edge(e.to,\
    \ e.from, e.cost, e.id);\n        }\n        is_build = true;\n    }\n\n    EdgeIterators\
    \ operator[](int i) {\n        if (!is_build) build();\n        return EdgeIterators(csr_edges.begin()\
    \ + start[i], csr_edges.begin() + start[i + 1]);\n    }\n\n    size_t size() const\
    \ { return (size_t)(n); }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, Graph<T>& g) {\n        os << \"[\";\n        for (int i = 0; i < (int)(g.size());\
    \ i++) {\n            os << \"[\";\n            for (int j = 0; j < (int)(g[i].size());\
    \ j++) {\n                os << g[i][j];\n                if (j + 1 != (int)(g[i].size()))\
    \ os << \", \";\n            }\n            os << \"]\";\n            if (i +\
    \ 1 != (int)(g.size())) os << \", \";\n        }\n        return os << \"]\";\n\
    \    }\n};\n#line 4 \"graph/read_graph.hpp\"\n\ntemplate <class T> Graph<T> read_graph(const\
    \ int n, const int m, const bool weight = false, const bool directed = false,\
    \ const int offset = 1) {\n    Graph<T> g(n, directed);\n    for (int i = 0; i\
    \ < m; i++) {\n        int a, b;\n        std::cin >> a >> b;\n        a -= offset,\
    \ b -= offset;\n        T c = 1;\n        if (weight) std::cin >> c;\n       \
    \ g.add_edge(a, b, c);\n    }\n    g.build();\n    return g;\n}\n\ntemplate <class\
    \ T> Graph<T> read_parent(const int n, const bool weight = false, const bool directed\
    \ = false, const int offset = 1) {\n    Graph<T> g(n, directed);\n    for (int\
    \ i = 1; i < n; i++) {\n        int p;\n        std::cin >> p;\n        p -= offset;\n\
    \        T c = 1;\n        if (weight) std::cin >> c;\n        g.add_edge(p, i,\
    \ c);\n    }\n    g.build();\n    return g;\n}\n#line 2 \"graph/heavy_light_decomposition.hpp\"\
    \n\n#line 4 \"graph/heavy_light_decomposition.hpp\"\n\n// Heavy-Light Decomposition\
    \ (\u30D1\u30B9\u30AF\u30A8\u30EA)\ntemplate <class T> struct HeavyLightDecomposition\
    \ {\n    int n;\n    // dfs_size\n    std::vector<int> subsize;  // subsize[v]\
    \ = v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\
    \n    std::vector<int> depth;    // depth[v] = v \u306E\u6DF1\u3055\n    std::vector<int>\
    \ parent;   // parent[v] = v \u306E\u89AA\u306E\u9802\u70B9\u756A\u53F7\n\n  \
    \  // dfs_hld\n    std::vector<int> vertices;  // Heavy-Edge \u304B\u3089\u512A\
    \u5148\u7684\u306B DFS \u3057\u305F\u3068\u304D\u306E\u9802\u70B9\u306E\u756A\u53F7\
    \u3092\u4E26\u3079\u305F\u3082\u306E, n \u8981\u7D20\n    std::vector<int> edges;\
    \     // Heavy-Edge \u304B\u3089\u512A\u5148\u7684\u306B DFS \u3057\u305F\u3068\
    \u304D\u306E\u8FBA\u306E\u756A\u53F7\u3092\u4E26\u3079\u305F\u3082\u306E, n -\
    \ 1 \u8981\u7D20\n    std::vector<int> pathtop;   // pathtop[v] = v \u3092\u542B\
    \u3080\u30D1\u30B9\u4E0A\u306E\u7956\u5148\n    std::vector<int> subbegin;  //\
    \ subbegin[v] = v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\
    \u70B9\u5217\u306E\u958B\u59CB\u4F4D\u7F6E, vertices \u306B\u304A\u3051\u308B\
    \ v \u306E\u767B\u5834\u4F4D\u7F6E\n    std::vector<int> subend;    // subend[v]\
    \ = v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u5217\
    \u306E\u7D42\u308F\u308A\n    std::vector<int> eindex;    // eindex[e] = edges\
    \ \u306B\u304A\u3051\u308B e \u306E\u767B\u5834\u4F4D\u7F6E\n\n    // Graph<T>\
    \ \u306E\u8FBA\u306E\u4E26\u3079\u66FF\u3048\u3092\u884C\u3046\u3053\u3068\u306B\
    \u6CE8\u610F\n    HeavyLightDecomposition(Graph<T>& g, const int root = 0) : n((int)(g.size())),\
    \ subsize(n, 1), depth(n, 0), parent(n, -1), pathtop(n, -1), subbegin(n, -1),\
    \ subend(n, -1), eindex(n - 1, -1) {\n        // \u90E8\u5206\u6728\u306E\u30B5\
    \u30A4\u30BA\u3092\u8A08\u7B97\n        auto dfs_size = [&](auto f, int cur, int\
    \ par) -> void {\n            parent[cur] = par;\n            // \u89AA\u65B9\u5411\
    \u3078\u306E\u8FBA\u3092\u672B\u5C3E\u306B\u79FB\u52D5\n            for (int i\
    \ = 0; i < (int)(g[cur].size()); i++) {\n                if (g[cur][i].to == par)\
    \ {\n                    std::swap(g[cur][i], g[cur][(int)(g[cur].size()) - 1]);\n\
    \                    break;\n                }\n            }\n            //\
    \ \u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\u304C\u6700\u5927\u306E\u3082\u306E\
    \u3092\u5148\u982D\u306B\u79FB\u52D5\n            for (auto&& e : g[cur]) {\n\
    \                if (e.to == par) continue;\n                depth[e.to] = depth[cur]\
    \ + 1;\n                f(f, e.to, cur);\n                subsize[cur] += subsize[e.to];\n\
    \                if (subsize[e.to] > subsize[g[cur][0].to]) {\n              \
    \      std::swap(e, g[cur][0]);\n                }\n            }\n        };\n\
    \        dfs_size(dfs_size, root, -1);\n\n        // \u9802\u70B9\u3092\u4E26\u3079\
    \u308B\n        vertices.reserve(n);\n        edges.reserve(n - 1);\n        auto\
    \ dfs_hld = [&](auto f, int cur, int par, int top) -> void {\n            pathtop[cur]\
    \ = top;\n            subbegin[cur] = (int)(vertices.size());\n            vertices.push_back(cur);\n\
    \n            for (auto&& e : g[cur]) {\n                if (e.to == par) continue;\n\
    \                eindex[e.id] = (int)(edges.size());\n                edges.push_back(e.id);\n\
    \                // top \u306F heavy-edge \u306B\u5BFE\u3057\u3066\u306E\u307F\
    \u5F15\u304D\u7D99\u304C\u308C\u308B\n                f(f, e.to, cur, (e.to ==\
    \ g[cur][0].to ? top : e.to));\n            }\n            subend[cur] = (int)(vertices.size());\n\
    \        };\n        dfs_hld(dfs_hld, root, -1, root);\n    }\n\n    int lca(int\
    \ u, int v) {\n        // \u540C\u3058\u30D1\u30B9\u307E\u3067\u4E0A\u304C\u308B\
    \n        while (pathtop[u] != pathtop[v]) {\n            if (subbegin[u] > subbegin[v])\
    \ {\n                u = parent[pathtop[u]];\n            } else {\n         \
    \       v = parent[pathtop[v]];\n            }\n        }\n        if (subbegin[u]\
    \ > subbegin[v]) std::swap(u, v);\n        return u;\n    }\n\n    // u - v \u30D1\
    \u30B9\u306B\u5BFE\u5FDC\u3059\u308B\u533A\u9593\n    // is_edges = true \u306A\
    \u3089 edges \u306B\u5BFE\u5FDC\u3059\u308B\u533A\u9593, false \u306A\u3089 vertices\
    \ \u306B\u5BFE\u5FDC\u3059\u308B\u533A\u9593\n    std::vector<std::pair<int, int>>\
    \ path_query(int u, int v, const bool is_edges) {\n        std::vector<std::pair<int,\
    \ int>> res;\n        while (pathtop[u] != pathtop[v]) {\n            if (subbegin[u]\
    \ > subbegin[v]) std::swap(u, v);\n            // subbegin[u] <= subbegin[v]\n\
    \            if (is_edges) {\n                // edges \u306B\u5BFE\u5FDC\u3059\
    \u308B\u533A\u9593\u306A\u306E\u3067 pathtop[u] \u304B\u3089 parent[pathtop[u]]\
    \ \u306B\u884C\u304F\u8FBA\u3082\u533A\u9593\u306B\u52A0\u3048\u308B\n       \
    \         res.emplace_back(subbegin[pathtop[v]] - 1, subbegin[v]);\n         \
    \   } else {\n                res.emplace_back(subbegin[pathtop[v]], subbegin[v]\
    \ + 1);\n            }\n            v = parent[pathtop[v]];\n        }\n     \
    \   if (subbegin[u] > subbegin[v]) std::swap(u, v);\n        if (is_edges) {\n\
    \            res.emplace_back(subbegin[u], subbegin[v]);\n        } else {\n \
    \           res.emplace_back(subbegin[u], subbegin[v] + 1);\n        }\n     \
    \   return res;\n    }\n\n    // u \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\
    \u306B\u5BFE\u5FDC\u3059\u308B\u533A\u9593\n    // is_edges = true \u306A\u3089\
    \ edges \u306B\u5BFE\u5FDC\u3059\u308B\u533A\u9593, false \u306A\u3089 vertices\
    \ \u306B\u5BFE\u5FDC\u3059\u308B\u533A\u9593\n    std::pair<int, int> subtree_query(int\
    \ u, const bool is_edges) {\n        if (is_edges) {\n            return {subbegin[u],\
    \ subend[u] - 1};\n        } else {\n            return {subbegin[u], subend[u]};\n\
    \        }\n    }\n};\n#line 4 \"data_structure/segment_tree.hpp\"\ntemplate <class\
    \ MS> struct SegmentTree {\n   public:\n    using S = typename MS::S;\n    SegmentTree()\
    \ : SegmentTree(0) {}\n    SegmentTree(int n) : SegmentTree(std::vector<S>(n,\
    \ MS::e())) {}\n    SegmentTree(const std::vector<S>& v) : n((int)(v.size()))\
    \ {\n        log = 0;\n        while ((1U << log) < (unsigned int)(n)) log++;\n\
    \        size = 1 << log;\n        d = std::vector<S>(size << 1, MS::e());\n \
    \       for (int i = 0; i < n; i++) d[i + size] = v[i];\n        for (int i =\
    \ size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void\
    \ set(int p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n\
    \        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n \
    \   }\n\n    void chset(int p, const S& x) {\n        assert(0 <= p and p < n);\n\
    \        p += size;\n        d[p] = MS::op(d[p], x);\n        for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n    }\n\n    S operator[](int p) const {\n \
    \       assert(0 <= p and p < n);\n        return d[p + size];\n    }\n\n    S\
    \ get(int p) const {\n        assert(0 <= p && p < n);\n        return d[p + size];\n\
    \    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l and l <= r and\
    \ r <= n);\n        S sml = MS::e(), smr = MS::e();\n        l += size;\n    \
    \    r += size;\n\n        while (l < r) {\n            if (l & 1) sml = MS::op(sml,\
    \ d[l++]);\n            if (r & 1) smr = MS::op(d[--r], smr);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n        return MS::op(sml, smr);\n    }\n\
    \n    S all_prod() const { return d[1]; }\n\n    template <class G> int max_right(int\
    \ l, G& g) const {\n        assert(0 <= l and l <= n);\n        assert(g(MS::e()));\n\
    \        if (l == n) return n;\n        l += size;\n        S sm = MS::e();\n\
    \        do {\n            while ((l & 1) == 0) l >>= 1;\n            if (!g(MS::op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l <<= 1;\n\
    \                    if (g(MS::op(sm, d[l]))) {\n                        sm =\
    \ MS::op(sm, d[l]);\n                        l++;\n                    }\n   \
    \             }\n                return l - size;\n            }\n           \
    \ sm = MS::op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n\
    \        return n;\n    }\n\n    template <class G> int min_left(int r, G& g)\
    \ const {\n        assert(0 <= r and r <= n);\n        assert(g(MS::e()));\n \
    \       if (r == 0) return 0;\n        r += size;\n        S sm = MS::e();\n \
    \       do {\n            r--;\n            while (r > 1 and (r & 1)) r >>= 1;\n\
    \            if (!g(MS::op(d[r], sm))) {\n                while (r < size) {\n\
    \                    r = (r << 1) | 1;\n                    if (g(MS::op(d[r],\
    \ sm))) {\n                        sm = MS::op(d[r], sm);\n                  \
    \      r--;\n                    }\n                }\n                return\
    \ r + 1 - size;\n            }\n            sm = MS::op(d[r], sm);\n        }\
    \ while ((r & -r) != r);\n        return 0;\n    }\n\n    std::vector<S> make_vector()\
    \ {\n        std::vector<S> vec(n);\n        for (int i = 0; i < n; i++) vec[i]\
    \ = get(i);\n        return vec;\n    }\n\n   private:\n    int n, log, size;\n\
    \    std::vector<S> d;\n    inline void update(int k) { d[k] = MS::op(d[k << 1],\
    \ d[(k << 1) | 1]); }\n};\n#line 2 \"algebra/monoid_s/monoid_sum.hpp\"\n// MS\n\
    template <class T> struct MonoidSum {\n    using S = T;\n    static constexpr\
    \ S op(S a, S b) { return a + b; }\n    static constexpr S e() { return T(0);\
    \ }\n};\n#line 10 \"verify/graph/heavy_light_decomposition_3.test.cpp\"\n\nint\
    \ main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<long long>\
    \ a(N);\n    for (int i = 0; i < N; i++) std::cin >> a[i];\n    auto g = read_parent<long\
    \ long>(N, false, false, 0);\n\n    const int root = 0;\n    HeavyLightDecomposition\
    \ hld(g, root);\n    std::vector<long long> segi(N);\n    for (int i = 0; i <\
    \ N; i++) segi[i] = a[hld.vertices[i]];\n    SegmentTree<MonoidSum<long long>>\
    \ seg(segi);\n\n    for (int i = 0; i < Q; i++) {\n        int type;\n       \
    \ std::cin >> type;\n        if (type == 0) {\n            int u, x;\n       \
    \     std::cin >> u >> x;\n            seg.chset(hld.subbegin[u], x);\n      \
    \  } else {\n            int u;\n            std::cin >> u;\n            auto\
    \ [l, r] = hld.subtree_query(u, false);\n            std::cout << seg.prod(l,\
    \ r) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <iostream>\n\n#include \"my_template.hpp\"\n#include \"graph/read_graph.hpp\"\
    \n#include \"graph/heavy_light_decomposition.hpp\"\n#include \"data_structure/segment_tree.hpp\"\
    \n#include \"algebra/monoid_s/monoid_sum.hpp\"\n\nint main() {\n    int N, Q;\n\
    \    std::cin >> N >> Q;\n    std::vector<long long> a(N);\n    for (int i = 0;\
    \ i < N; i++) std::cin >> a[i];\n    auto g = read_parent<long long>(N, false,\
    \ false, 0);\n\n    const int root = 0;\n    HeavyLightDecomposition hld(g, root);\n\
    \    std::vector<long long> segi(N);\n    for (int i = 0; i < N; i++) segi[i]\
    \ = a[hld.vertices[i]];\n    SegmentTree<MonoidSum<long long>> seg(segi);\n\n\
    \    for (int i = 0; i < Q; i++) {\n        int type;\n        std::cin >> type;\n\
    \        if (type == 0) {\n            int u, x;\n            std::cin >> u >>\
    \ x;\n            seg.chset(hld.subbegin[u], x);\n        } else {\n         \
    \   int u;\n            std::cin >> u;\n            auto [l, r] = hld.subtree_query(u,\
    \ false);\n            std::cout << seg.prod(l, r) << '\\n';\n        }\n    }\n\
    \    return 0;\n}"
  dependsOn:
  - my_template.hpp
  - graph/read_graph.hpp
  - graph/graph_template.hpp
  - graph/heavy_light_decomposition.hpp
  - data_structure/segment_tree.hpp
  - algebra/monoid_s/monoid_sum.hpp
  isVerificationFile: true
  path: verify/graph/heavy_light_decomposition_3.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 00:14:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/heavy_light_decomposition_3.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/heavy_light_decomposition_3.test.cpp
- /verify/verify/graph/heavy_light_decomposition_3.test.cpp.html
title: verify/graph/heavy_light_decomposition_3.test.cpp
---
