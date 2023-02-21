#pragma once

#include "geometry/point.hpp"

// polygon
using Polygon = std::vector<Point>;
std::istream &operator>>(std::istream &is, Polygon &p) {
    for (auto &&pi : p) is >> pi;
    return is;
}
std::ostream &operator<<(std::ostream &os, const Polygon &p) {
    for (auto &&pi : p) os << pi << " -> ";
    return os;
}