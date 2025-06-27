#include <bits/stdc++.h>
using namespace std;    

int main(){
ios_base::sync_with_stdio(false);   
cin.tie(0);
int n, m;
cin >> n >> m;
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        if(i == j){
            dp[i][j] = 0;
            continue;
        }
        for(int v = 1; v<i; v++){
            dp[i][j] = min(dp[i-v][j] + dp[v][j] + 1, dp[i][j]);
        }
        for(int v =1; v<j; v++){
            dp[i][j] = min(dp[i][j-v] + dp[i][v] + 1, dp[i][j]);
        }
    }
}
cout << dp[n][m] << "\n";
    return 0;
}