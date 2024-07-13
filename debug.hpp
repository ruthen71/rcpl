#pragma once

#include <iomanip>
#include <utility>
#include <tuple>
#include <array>
#include <vector>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>

#define show(x) std::cerr << std::setprecision(15) << __LINE__ << " : " << #x << " = " << (x) << std::endl

// pair
template <class OStream, class T, class U> OStream& operator<<(OStream& os, const std::pair<T, U>& pir);
template <class OStream, class T, class U> OStream& operator<<(OStream& os, const std::pair<T, U>& pir) { return os << "(" << pir.first << ", " << pir.second << ")"; }
// tuple
template <class OStream, class... T> OStream& operator<<(OStream& os, const std::tuple<T...>& tpl);
template <class OStream, class... T> OStream& operator<<(OStream& os, const std::tuple<T...>& tpl) {
    os << "(";
    std::apply([&os](auto&&... args) { ((os << args << ", "), ...); }, tpl);
    return os << ")";
}
// array
template <class OStream, class T, size_t sz> OStream& operator<<(OStream& os, const std::array<T, sz>& arr);
template <class OStream, class T, size_t sz> OStream& operator<<(OStream& os, const std::array<T, sz>& arr) {
    os << "[ ";
    for (auto v : arr) os << v << " ";
    return os << "]";
}
// vector
template <class OStream, class T> OStream& operator<<(OStream& os, const std::vector<T>& vec);
template <class OStream, class T> OStream& operator<<(OStream& os, const std::vector<T>& vec) {
    os << "[ ";
    for (auto v : vec) os << v << " ";
    return os << "]";
}
// deque
template <class OStream, class T> OStream& operator<<(OStream& os, const std::deque<T>& vec);
template <class OStream, class T> OStream& operator<<(OStream& os, const std::deque<T>& vec) {
    os << "[ ";
    for (auto v : vec) os << v << " ";
    return os << "]";
}
// set
template <class OStream, class T> OStream& operator<<(OStream& os, const std::set<T>& vec);
template <class OStream, class T> OStream& operator<<(OStream& os, const std::set<T>& vec) {
    os << "{ ";
    for (auto v : vec) os << v << " ";
    return os << "}";
}
// multiset
template <class OStream, class T> OStream& operator<<(OStream& os, const std::multiset<T>& vec);
template <class OStream, class T> OStream& operator<<(OStream& os, const std::multiset<T>& vec) {
    os << "{ ";
    for (auto v : vec) os << v << " ";
    return os << "}";
}
// unordered_set
template <class OStream, class T, class TH> OStream& operator<<(OStream& os, const std::unordered_set<T, TH>& vec);
template <class OStream, class T, class TH> OStream& operator<<(OStream& os, const std::unordered_set<T, TH>& vec) {
    os << "{ ";
    for (auto v : vec) os << v << " ";
    return os << "}";
}
// unordered_multiset
template <class OStream, class T, class TH> OStream& operator<<(OStream& os, const std::unordered_multiset<T, TH>& vec);
template <class OStream, class T, class TH> OStream& operator<<(OStream& os, const std::unordered_multiset<T, TH>& vec) {
    os << "{ ";
    for (auto v : vec) os << v << " ";
    return os << "}";
}
// map
template <class OStream, class TK, class TV> OStream& operator<<(OStream& os, const std::map<TK, TV>& mp);
template <class OStream, class TK, class TV> OStream& operator<<(OStream& os, const std::map<TK, TV>& mp) {
    os << "{ ";
    for (auto v : mp) os << v << " ";
    return os << "}";
}
// unordered_map
template <class OStream, class TK, class TV, class TH> OStream& operator<<(OStream& os, const std::unordered_map<TK, TV, TH>& mp);
template <class OStream, class TK, class TV, class TH> OStream& operator<<(OStream& os, const std::unordered_map<TK, TV, TH>& mp) {
    os << "{ ";
    for (auto v : mp) os << v << " ";
    return os << "}";
}
// queue
template <class OStream, class T> OStream& operator<<(OStream& os, std::queue<T> que);
template <class OStream, class T> OStream& operator<<(OStream& os, std::queue<T> que) {
    std::vector<T> vec;
    while (!que.empty()) {
        auto v = que.front();
        que.pop();
        vec.push_back(v);
    }
    os << vec;
    for (auto v : vec) que.push(v);
    return os;
}
// priority_queue
template <class OStream, class T, class Container, class Compare> OStream& operator<<(OStream& os, std::priority_queue<T, Container, Compare> pque);
template <class OStream, class T, class Container, class Compare> OStream& operator<<(OStream& os, std::priority_queue<T, Container, Compare> pque) {
    std::vector<T> vec;
    while (!pque.empty()) {
        auto v = pque.top();
        pque.pop();
        vec.push_back(v);
    }
    os << vec;
    for (auto v : vec) pque.push(v);
    return os;
}