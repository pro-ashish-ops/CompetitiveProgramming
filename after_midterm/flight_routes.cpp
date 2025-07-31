#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e5 + 5;
vector<pair<int,int>> adj[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // Min-heap: (cost, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});

    vector<vector<int>> dp(n + 1);

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        if (dp[node].size() >= k) continue;

        dp[node].push_back(cost);

        for (auto [neigh, wt] : adj[node]) {
            pq.push({cost + wt, neigh});
        }
    }

    for (int i = 0; i < k; i++) {
        cout << dp[n][i] << " ";
    }
    cout << "\n";

    return 0;
}
