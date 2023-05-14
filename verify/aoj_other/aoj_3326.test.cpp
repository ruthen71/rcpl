#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3326"

#include "icpc/template.hpp"
#include "icpc/segtree.hpp"

const long long INF = 1LL << 60;
using S = pair<long long, long long>;
S op(S a, S b) {
    return {min(a.first, b.first), max(a.second, b.second)};
}
S e() {
    return {INF, -INF};
}

int main() {
    int N, Q;
    cin >> N >> Q;
    V<ll> A(N);
    REP(i, N) cin >> A[i];
    V<pair<ll, ll>> B(N);
    REP(i, N) B[i] = {A[i], A[i]};
    Segtree<S, op, e> seg(B);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k;
            ll x;
            cin >> k >> x;
            k--;
            seg.set(k, {A[k] + x, A[k] + x});
            A[k] += x;
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            auto p = seg.prod(l, r);
            cout << (p.first == p.second ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}