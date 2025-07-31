#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent, vis;
vector<int> cycle;

bool dfs(int u, int p) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            // Found a cycle
            cycle.push_back(v);
            int cur = u;
            while (cur != v) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(v);
            reverse(cycle.begin(), cycle.end());
            return true;
        } else {
            parent[v] = u;
            if (dfs(v, u)) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    parent.assign(n + 1, 0);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, 0)) {
                cout << cycle.size() << "\n";
                for (int x : cycle) cout << x << " ";
                cout << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
