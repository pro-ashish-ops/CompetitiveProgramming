#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18
vector<int> adj[200005];

void dfs(int u, vector<vector<int>>& dp, int par) {
    dp[u][0] = 0; // not taking this node
    dp[u][1] = 0; // taking this node

     for (auto v : adj[u]) {
        if (v == par) continue; // avoid going back to parent
        dfs(v, dp,u);
        dp[u][0] += dp[v][1];
    }

    for (auto v : adj[u]) {
        if (v == par) continue; // avoid going back to parent
        // if we take u, we can only take one of the children
        dp[u][1] = max(dp[u][1], 1 + dp[v][0] + (dp[u][0] - dp[v][1]));
    }
}

    

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>>dp(n + 1, vector<int>(2, 0));
    dfs(1, dp, -1);
    cout << max(dp[1][0], dp[1][1]) << endl;
    
    return 0;
}