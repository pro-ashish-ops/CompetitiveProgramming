#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;
vector<tuple<int, int, int>> edges; // store all edges
vector<int> dist, parent;

int n, m;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    dist.assign(n + 1, 0); // or INF if needed
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    int x = -1;

    for (int i = 1; i <= n; i++) {
        x = -1;
        for (auto [u, v, w] : edges) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        // To find cycle
        for (int i = 0; i < n; i++) {
            x = parent[x];
        }

        vector<int> cycle;
        int cur = x;
        do {
            cycle.push_back(cur);
            cur = parent[cur];
        } while (cur != x);
        cycle.push_back(x);
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int node : cycle) cout << node << " ";
        cout << "\n";
    }

    return 0;
}
