#pragma once

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i, n) for (int i = 0; i < (n); i++)
template <class T> using V = vector<T>;
template <class T> ostream& operator<<(ostream &os, const V<T>& v) {
    os << "[ ";
    for (auto &vi : v) os << vi << ", ";
    return os << "]";
}

#if 1
#define show(x) cerr << __LINE__ << " : " << #x << " = " << x << endl;
#else
#define show(x) true
#endif

int main() {
    return 0;
}