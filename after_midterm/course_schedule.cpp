#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
vector<int> adj[100001];
vector<bool> vis(100001, false);
stack<int> ans;
vector<bool> instack(100001,false);

void dfs(int node){
    vis[node] = true;
    instack[node] = true;
    for(auto child: adj[node]){
        if(!vis[child]){
            dfs(child);
        }else if(instack[child]){
            cout<<"IMPOSSIBLE";
            exit(0);
        }
    }
    instack[node] = false;
    ans.push(node);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i =1; i<= m; i++){
        int a,b;
        cin>>a >>b;
        adj[a].push_back(b);
    }
    for(int i = 1; i<= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;

    return 0;
}