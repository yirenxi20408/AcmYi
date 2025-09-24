#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define int long long
#define endl '\n'
#define fastio    ios::sync_with_stdio(false); cin.tie(nullptr)
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)

void solve() {
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    
    set<int> black_cells;
    
    // Read initial black cells
    rep(i, 1, m) {
        int pos;
        cin >> pos;
        black_cells.insert(pos);
    }
    
    // Process each prefix of commands
    rep(prefix_len, 1, n) {
        int pos = 1;  // Start at cell 1
        
        // Execute commands for this prefix
        rep(cmd_idx, 0, prefix_len - 1) {
            if (s[cmd_idx] == 'A') {
                pos++;
            } else {  // s[cmd_idx] == 'B'
                // Find next white cell after pos
                // This is efficient because set.count() is O(log n) and 
                // we only increment pos until we find a white cell
                pos++;
                while (black_cells.count(pos)) {
                    pos++;
                }
            }
        }
        
        // Mark final position as black
        black_cells.insert(pos);
    }
    
    // Output results
    cout << black_cells.size() << endl;
    for (int pos : black_cells) {
        cout << pos << " ";
    }
    cout << endl;
}

signed main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}