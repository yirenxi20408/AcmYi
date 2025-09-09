#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll S = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) S += a[i];
            else S -= a[i];
        }
        ll G = 0;
        
        // same parity swaps
        // odd-odd
        if (n >= 3) {
            int first_odd = 1;
            int last_odd = (n % 2 == 1 ? n : n-1);
            if (last_odd > first_odd) G = max(G, (ll)(last_odd - first_odd));
            // even-even
            int first_even = 2;
            int last_even = (n % 2 == 0 ? n : n-1);
            if (last_even > first_even) G = max(G, (ll)(last_even - first_even));
        }
        // cross parity swaps
        // odd-even: l odd, r even
        ll minX = LLONG_MAX, maxB = LLONG_MIN;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                ll X = 2*a[i] + i;
                minX = min(minX, X);
            } else {
                ll B = 2*a[i] + i;
                maxB = max(maxB, B);
            }
        }
        if (minX != LLONG_MAX && maxB != LLONG_MIN) {
            G = max(G, maxB - minX);
        }
        // even-odd: l even, r odd
        ll maxC = LLONG_MIN, minD = LLONG_MAX;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                ll C = 2*a[i] - i;
                maxC = max(maxC, C);
            } else {
                ll D = 2*a[i] - i;
                minD = min(minD, D);
            }
        }
        if (maxC != LLONG_MIN && minD != LLONG_MAX) {
            G = max(G, maxC - minD);
        }
        
        cout << S + G << '\n';
    }
    return 0;
}