#pragma once

#include <type_traits>

// Constants (EPS, PI)
// EPS の変更は Constants<T>::set_eps(new_eps) で
template <class T> struct Constants {
    static T EPS;
    static void set_eps(const T e) { EPS = e; }
    static constexpr T PI = 3.14159'26535'89793L;
};

template <> double Constants<double>::EPS = 1e-9;
template <> long double Constants<long double>::EPS = 1e-12;
template <> long long Constants<long long>::EPS = 0;

// base functions
template <class T> inline int sign(const T x) { return x < -Constants<T>::EPS ? -1 : (x > Constants<T>::EPS ? 1 : 0); }
template <class T> inline bool equal(const T a, const T b) { return sign(a - b) == 0; }
template <class T> inline T radian_to_degree(const T r) { return r * 180.0 / Constants<T>::PI; }
template <class T> inline T degree_to_radian(const T d) { return d * Constants<T>::PI / 180.0; }

// type traits
template <class T> using is_geometry_floating_point = typename std::conditional<std::is_same<T, double>::value || std::is_same<T, long double>::value, std::true_type, std::false_type>::type;
template <class T> using is_geometry_integer = typename std::conditional<std::is_same<T, long long>::value, std::true_type, std::false_type>::type;
template <class T> using is_geometry = typename std::conditional<is_geometry_floating_point<T>::value || is_geometry_integer<T>::value, std::true_type, std::false_type>::type;
