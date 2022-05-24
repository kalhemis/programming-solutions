/* 
 * Author: hemis, Kalpesh Patel
 * जान है तो जहान है
*/

#include <bits/stdc++.h>
using namespace std;

using t3 = tuple<int, int, int>;

bool multi = 1;

void solve() {

    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> b(n);
    for (auto& x : b) cin >> x;

    map<t3, int> m;
    priority_queue<t3,vector<t3>,greater<t3>> q;
    for (int i = 0; i < n; i++) {
        q.push({a[i], b[i], i});
        m[make_tuple(a[i], b[i], i)] = i;
    }

    vector<int> lookup(n);
    iota(lookup.begin(), lookup.end(), 0);
    vector<pair<int, int>> swaps;
    for (int i = 0; i < n; i++) {
        auto [x, y, z] = q.top();
        q.pop();
        int k = m[make_tuple(x, y, z)];
        if (i != k) {
            swaps.emplace_back(i, k);
            int idx = lookup[i];
            m[make_tuple(x, y, z)] = i;
            m[make_tuple(a[i], b[i], idx)] = k;
            lookup[i] = z;
            lookup[k] = idx; 
            a[k] = a[i]; b[k] = b[i];
            a[i] = x; b[i] = y;
        }
    }

    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            flag = false;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        if (b[i] < b[i-1]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << (int) swaps.size() << endl;
        for (auto [x, y] : swaps) cout << x + 1 << " " << y + 1 << endl;
    } else {
        cout << -1 << endl;
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

