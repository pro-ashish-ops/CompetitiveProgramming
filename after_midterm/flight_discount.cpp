#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int n, m;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // dist[u][0] = min cost to reach u without using coupon
    // dist[u][1] = min cost to reach u after using coupon
    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0}); // {cost, node, coupon_used}

    while (!pq.empty()) {
        auto [d, u, used] = pq.top();
        pq.pop();

        if (d > dist[u][used]) continue;

        for (auto [v, w] : adj[u]) {
            // Move without using coupon
            if (dist[v][used] > d + w) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }

            // Use coupon (only if not used yet)
            if (used == 0 && dist[v][1] > d + w / 2) {
                dist[v][1] = d + w / 2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << "\n";

    return 0;
}
