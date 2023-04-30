#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2286"

#include "icpc/template.hpp"
#include "icpc/dice.hpp"

void solve(int N) {
    vector paint(N, map<pair<int, int>, int>());
    REP(i, N) {
        int cx, cy;
        cin >> cx >> cy;
        vector<long long> num(6);
        REP(j, 6) cin >> num[j];
        string rot;
        cin >> rot;
        Dice dice(num);
        paint[i][{cx, cy}] = dice.d[4];
        for (auto c : rot) {
            if (c == 'L') {
                dice.xm();
                cx--;
            }
            if (c == 'R') {
                dice.xp();
                cx++;
            }
            if (c == 'F') {
                dice.ym();
                cy--;
            }
            if (c == 'B') {
                dice.yp();
                cy++;
            }
            paint[i][{cx, cy}] = dice.d[4];
        }
    }
    int N2 = 1 << N;
    vector dp(N2, 0);
    vector points(N2, set<pair<int,int>>());
    REP(bit, N2) {
        REP(i, N) {
            if (bit >> i & 1) {
                for (auto &[p, sc] : paint[i]) {
                    auto [x, y] = p;
                    points[bit].insert({x, y});
                }
            }
        }
    }
    REP(bit, N2) {
        REP(i, N) {
            if (bit >> i & 1) continue;
            int nx = 0;
            for (auto &[p, sc] : paint[i]) {
                auto [x, y] = p;
                if (points[bit].count({x, y}) == 0) {
                    nx += sc;
                }
            }
            dp[bit | (1 << i)] = max(dp[bit | (1 << i)], dp[bit] + nx);
        }
    }
    int ans = 0;
    REP(bit, N2) ans = max(ans, dp[bit]);
    cout << ans << endl;
}

int main() {
    int N;
    while (cin >> N, !(N == 0)) solve(N);
    return 0;
}