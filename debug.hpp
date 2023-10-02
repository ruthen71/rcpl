#pragma once

#include <iomanip>
#define show(x) std::cerr << std::setprecision(15) << __LINE__ << " : " << #x << " = " << (x) << std::endl

#include <utility>
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pir) { return os << "(" << pir.first << ", " << pir.second << ")"; }

#include <tuple>
template <class OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...> &tpl) {
    os << "(";
    std::apply([&os](auto &&...args) { ((os << args << ", "), ...); }, tpl);
    return os << ")";
}

#include <array>
template <class OStream, class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz> &arr) {
    os << "[ ";
    for (auto v : arr) os << v << " ";
    return os << "]";
}

#include <vector>
template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) {
    os << "[ ";
    for (auto v : vec) os << v << " ";
    return os << "]";
}

#include <deque>
template <class OStream, class T> OStream &operator<<(OStream &os, const std::deque<T> &vec) {
    os << "[ ";
    for (auto v : vec) os << v << " ";
    return os << "]";
}

#include <set>
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

#include <unordered_set>
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

#include <map>
template <class OStream, class TK, class TV> OStream &operator<<(OStream &os, const std::map<TK, TV> &mp) {
    os << "{ ";
    for (auto v : mp) os << v << " ";
    return os << "}";
}

#include <unordered_map>
template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp) {
    os << "{ ";
    for (auto v : mp) os << v << " ";
    return os << "}";
}