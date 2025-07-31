#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define REP(i,n) for (int i = 1; i <= n; i++)
 
vi ar[100001];
bool vis[100001];
 
void dfs(int node){
	vis[node] = 1;
	
	for(int child : ar[node])
	if(vis[child] == 0) dfs(child);
}
 
int main()
{
	int n , m , a , b;
	
	vi res;
	
	cin>>n>>m;
	REP(i , m) cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);
	
	REP(i , n)
	if(vis[i] == 0)
	dfs(i) , res.push_back(i);
	
	cout<<res.size()-1<<endl;
	for(int i=1;i<res.size();i++)
	cout<<res[i-1]<<" "<<res[i]<<endl;
}
