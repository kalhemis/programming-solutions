/* 
 * Author: hemis, Kalpesh Patel
 * जान है तो जहान है
*/

#include <bits/stdc++.h>
using namespace std;

bool multi = 1;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int m; cin >> m;
    vector<int> b(m);
    for (auto& x : b) cin >> x;

    int alice = -1;
    for (auto x : a) {
        alice = max(x, alice);
    }
    
    int bob = -1;
    for (auto x : b) {
        bob = max(x, bob);
    }

    if (alice >= bob) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

    if (alice <= bob) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int tests = 1;
    if (multi) cin >> tests;
    while (tests--) solve();
    return 0;
}
