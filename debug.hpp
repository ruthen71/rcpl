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

#define show(x) std::cerr << std::setprecision(15) << __LINE__ << " : " << #x << " = " << (x) << std::endl

template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pir);
template <class OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...> &tpl);
template <class OStream, class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz> &arr);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::deque<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::set<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::multiset<T> &vec);
template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec);
template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_multiset<T, TH> &vec);
template <class OStream, class TK, class TV> OStream &operator<<(OStream &os, const std::map<TK, TV> &mp);
template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp);

template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pir) { return os << "(" << pir.first << ", " << pir.second << ")"; }
template <class OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...> &tpl) {
    os << "(";
    std::apply([&os](auto &&...args) { ((os << args << ", "), ...); }, tpl);
    return os << ")";
}
template <class OStream, class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz> &arr) {
    os << "[ ";
    for (auto v : arr) os << v << " ";
    return os << "]";
}
template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) {
    os << "[ ";
    for (auto v : vec) os << v << " ";
    return os << "]";
}
template <class OStream, class T> OStream &operator<<(OStream &os, const std::deque<T> &vec) {
    os << "[ ";
    for (auto v : vec) os << v << " ";
    return os << "]";
}
template <class OStream, class T> OStream &operator<<(OStream &os, const std::set<T> &vec) {
    os << "{ ";
    for (auto v : vec) os << v << " ";
    return os << "}";
}
template <class OStream, class T> OStream &operator<<(OStream &os, const std::multiset<T> &vec) {
    os << "{ ";
    for (auto v : vec) os << v << " ";
    return os << "}";
}
template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec) {
    os << "{ ";
    for (auto v : vec) os << v << " ";
    return os << "}";
}
template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_multiset<T, TH> &vec) {
    os << "{ ";
    for (auto v : vec) os << v << " ";
    return os << "}";
}
template <class OStream, class TK, class TV> OStream &operator<<(OStream &os, const std::map<TK, TV> &mp) {
    os << "{ ";
    for (auto v : mp) os << v << " ";
    return os << "}";
}
template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp) {
    os << "{ ";
    for (auto v : mp) os << v << " ";
    return os << "}";
}