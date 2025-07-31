#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define REP(i, n) for (int i = 1; i <= n; i++)

vi fr[100001];
bool vis[100001];
int parent[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    REP(i, m)
        cin >> a >> b,
        fr[a].push_back(b), fr[b].push_back(a);

    vis[1] = true;
    vector<int> res(n + 1, 0);
    queue<int> q;
    q.push(1);
    res[1] = 1;
    for(int i = 1; i<= n; i++){
        if(!vis[i]){
            q.push(i);
        }
   
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        if(res[s] == 0 and !vis[s]) res[s] =1;
        for (auto neighbor : fr[s])
        {
            if (!vis[neighbor])
            {
                vis[neighbor] = true;
                res[neighbor] = (res[s] == 1 ? 2 : 1);
                q.push(neighbor);
            }
            else if (res[neighbor] == res[s])
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

}
    for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
}
    cout << "\n";
    return 0;
}