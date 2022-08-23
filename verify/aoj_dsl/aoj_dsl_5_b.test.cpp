#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include <bits/stdc++.h>
using namespace std;

#include "src/data_structure/cumulative_sum_2d.hpp"

int main() {
    int N;
    cin >> N;
    int M = 1000;
    cumulative_sum_2d<int> rui(M + 1, M + 1);
    while (N--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rui.imos(x1, y1, x2, y2);
    }
    rui.build();
    int ans = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++) ans = max(ans, rui.get(i, j));
    cout << ans << '\n';
    return 0;
}