#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define REP(i,n) for (int i = 1; i <= n; i++)
 
vi ar[100001];
bool vis[100001];
int parent[100001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m,a,b;
    cin>>n>>m;
    REP(i,m) cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);

    vis[1] = true;
    parent[1] =  -1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int s = q.front(); q.pop();
        if(s == n) break;
        for(auto child: ar[s]){
            if(vis[child]) continue;
            vis[child] = true;
            parent[child] = s;
            q.push(child);
        }
    }
    if(!vis[n]){
        cout<< "IMPOSSIBLE";
    }
    else{
        vector<int>path;
        for(int curr = n; curr!= -1; curr = parent[curr]){
            path.push_back(curr);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (int x : path) cout << x << " ";
        cout << "\n";
    }

    return 0;
}