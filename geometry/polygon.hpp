#pragma once

#include "geometry/point.hpp"

// polygon
template <typename T> using Polygon = std::vector<Point<T>>;
template <typename T> std::istream &operator>>(std::istream &is, Polygon<T> &p) {
    for (auto &&pi : p) is >> pi;
    return is;
}
template <typename T> std::ostream &operator<<(std::ostream &os, const Polygon<T> &p) {
    for (auto &&pi : p) os << pi << " -> ";
    return os;
}