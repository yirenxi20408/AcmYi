#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define int long long
#define endl '\n'
#define fastio    ios::sync_with_stdio(false); cin.tie(nullptr)
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) {
        cin >> a[i];
    }

    int base = 0;
    rep(i, 1, n) {
        base += (i % 2 ? a[i] : -a[i]);
    }

    int best = 0;

    if (n >= 3) {
        int jil = 1, jir = (n % 2 ? n : n - 1);
        if (jir > jil) best = max(best, jir - jil);

        int oul = 2, our = (n % 2 == 0 ? n : n - 1);
        if (our > oul) best = max(best, our - oul);
    }
    int mn = inf, mx = -inf;
    rep(i, 1, n) {
        if (i % 2) {
            mn = min(mn, 2 * a[i] + i);
        } else {
            mx = max(mx, 2 * a[i] + i);
        }
    }
    if (mn < inf && mx > -inf) {
        best = max(best, mx - mn);
    }
    mn = inf, mx = -inf;
    rep(i, 1, n) {
        if (i % 2 == 0) {
            mx = max(mx, 2 * a[i] - i);
        } else {
            mn = min(mn, 2 * a[i] - i);
        }
    }
    if (mn < inf && mx > -inf) {
        best = max(best, mx - mn);
    }
    int ans = base + best;
    cout << ans << endl;
}

signed main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}