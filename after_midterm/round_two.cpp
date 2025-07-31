#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> adj[100001];
vector<bool> vis(100001, false);
vector<bool> inStack(100001, false);
vector<int> parent(100001, -1);
int cycle_start = -1, cycle_end = -1;

bool dfs(int node) {
    vis[node] = true;
    inStack[node] = true;

    for (auto child : adj[node]) {
        if (!vis[child]) {
            parent[child] = node;
            if (dfs(child)) return true;
        } else if (inStack[child]) {
            cycle_start = child;
            cycle_end = node;
            return true;
        }
    }
    inStack[node] = false;
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i)) break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        int v = cycle_end;
        while (v != cycle_start) {
            cycle.push_back(v);
            v = parent[v];
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (auto x : cycle) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
