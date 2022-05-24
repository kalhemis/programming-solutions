/* 
 * Author: hemis, Kalpesh Patel
 * मनुष्य अपने विश्वास से निर्मित होता है। जैसा वह मानता है, वैसा ही वह है।
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct graph {

    struct edges {
        int to = -1;
        edges(int _to) : to(_to) {};
    };

    int n;
    vector<vector<edges>> adj;
    vector<int> dist;
    vector<bool> visited;
    vector<int> prev;

    graph(int _n) {
        int n = _n;
        dist.resize(n, INT_MAX);
        adj.resize(n);
        visited.resize(n);
        prev.resize(n, -1);
    }

    void add_directional_edge(int from, int to) {
        adj[from].push_back(to);
    }

    void add_bidirectional_edge(int a, int b) {
        add_directional_edge(a, b);
        add_directional_edge(b, a);
    }

    void bfs(int source) {
        queue<int> q;
        q.push(source);
        dist[source] = 0;
        visited[source] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& e : adj[u]) {
                int to = e.to;
                if (visited[to]) continue;
                visited[to] = true;
                dist[to] = dist[u] + 1;
                prev[to] = u;
                q.push(to);
            }
        }
    }

    vector<int> restore_path(int s, int t) {
        vector<int> path = {t};
        while (t != s) {
            t = prev[t];
            path.push_back(t);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

bool MULTI_TEST = 0;

void solve() {
    int n; cin >> n;
    i64 x; cin >> x;
    
    map<i64, bool> m;
    queue<pair<i64, int>> q;
    q.push({x, 0});
    int target = -1;
    vector<pair<int, int>> edges;
    
    int total = 0;
    while (!q.empty()) {
        auto [u, idx] = q.front();
        q.pop();
        m[u] = true;

        string s = to_string(u);

        vector<bool> digits(10);
        for (auto c : s) digits[c - '0'] = true;

        for (int i = 0; i < 10; i++) {
            if (digits[i] == true) {
                i64 a = u * i;
                string t = to_string(a);
                int sz2 = (int) t.length();
                if (m.find(a) == m.end() && sz2 <= n)  {
                    total++;
                    m[a] = true;
                    q.push({a, total});
                    edges.emplace_back(idx, total);
                }
                if ((int) to_string(a).length() == n) {
                    target = total;
                    q = {};
                }
            }
        }
    }

    if (target == -1) {
        cout << -1 << endl;
        return;
    }

    graph g = graph(total + 1);
    for (auto [x, y] : edges) {
        g.add_directional_edge(x, y);
    }

    g.bfs(0);
    cout << g.dist[target] << endl;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int TESTS = 1;
    if (MULTI_TEST) cin >> TESTS;
    while (TESTS--) solve();
    return 0;
}
