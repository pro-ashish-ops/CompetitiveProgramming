#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> adj[100001];
vector<bool> vis(100001, false);
vector<int> dist(100001,1);

void dfs(int i){
    vis[i] = true;
    for(auto child: adj[i]){
        if(!vis[child]){
            dfs(child);
            dist[i] = max(dist[i], dist[child]+1);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n>> m;

    for(int i = 1; i<= m; i++){
        int a,b;
        cin>> a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    int max_height = 0;
    for(int i = 1; i <= n; i++){
        max_height = max(max_height, dist[i]);
    }   
    cout << max_height << endl;


    return 0;
}