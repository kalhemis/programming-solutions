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

    int start = 0;
    for (auto x : b) {
        start = (start + x) % n;
    }
    cout << a[start] << endl;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int tests = 1;
    if (multi) cin >> tests;
    while (tests--) solve();
    return 0;
}
