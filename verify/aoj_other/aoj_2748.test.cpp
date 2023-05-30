#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2748"

#include "icpc/template.hpp"
#include "icpc/scc.hpp"

void solve(int N) {
    vector<vector<int>> G(N);
    vector<double> p(N);
    REP(i, N) {
        cin >> p[i];
        int m;
        cin >> m;
        REP(j, m) {
            int a;
            cin >> a;
            a--;
            G[i].push_back(a);
        }
    }
    auto sccvec = scc(G);
    vector<int> seen(N);
    double ans = 1;
    for (auto& vec : sccvec) {
        if (seen[vec[0]]) continue;
        double cur = 1;
        queue<int> que;
        for (auto& vi : vec) {
            if (seen[vi]) continue;
            cur *= p[vi];
            que.push(vi);
            seen[vi] = 1;
        }
        ans *= 1 - cur;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto& e : G[v]) {
                if (seen[e]) continue;
                seen[e] = 1;
                que.push(e);
            }
        }
    }
    cout << fixed << setprecision(15) << ans << '\n';
}

int main() {
    int N;
    while (cin >> N, !(N == 0)) solve(N);
    return 0;
}