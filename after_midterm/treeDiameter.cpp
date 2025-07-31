#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> adj[200005];
vector<bool>vis(200005, false);
vector<int> dist(200005,0);

void dfs(int i){
    vis[i] = true;
    for(auto child: adj[i]){
        if(!vis[child]){
            vis[child] = true;
            dist[child] = dist[i] + 1;
            dfs(child);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    int max_dist = 0, farthest_node = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
            farthest_node = i;
        }
    }
    vis.assign(200005, false);
    dist.assign(200005, 0);
    dfs(farthest_node);
    max_dist = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
        }
    }

    cout<< max_dist << endl;
    return 0;
}