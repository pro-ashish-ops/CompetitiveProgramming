#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define double long double

vector<pair<int,int>> adj[100001];
vector<bool> vis(100001,false);
const int INF= 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b,d;
    cin>>n>>m;
        for(int j=1; j<= m; j++){
            cin>> a>>b>>d;
            adj[a].push_back({b,d});
        }
    
    vector<int> distance(n+1, LLONG_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        int a = pq.top().second; pq.pop();
        if(vis[a]) continue;
        vis[a] = true;
        for(auto u: adj[a]){
            int b = u.first, w = u.second;
            if(distance[a]+w< distance[b]){
                distance[b] = distance[a]+w;
                pq.push({distance[b],b});
            }
        }
    }

    for(int d =1; d<= n; d++) cout<<distance[d]<<" ";
    cout<<"\n";

    return 0;
}