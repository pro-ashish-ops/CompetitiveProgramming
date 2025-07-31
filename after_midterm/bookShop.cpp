#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin>> n>>x;
    vector<vector<int>>dp(n+1, vector<int>(x+1,0));
    vector<int> h(n+1), s(n+1);
    for(int i = 1; i<= n; i++){
        cin>> h[i];
    }
    for(int i = 1; i<=n; i++){
        cin>> s[i];
    }

    //transition 
    for(int i = 1; i<= n; i++){
        for (int j = 0; j <= x; j++) {
    dp[i][j] = dp[i-1][j]; // Don't take item i
    if (j >= h[i]) {
        dp[i][j] = max(dp[i][j], dp[i-1][j - h[i]] + s[i]); // Take item i
    }
}
    }
    cout<< dp[n][x];

    return 0;
}