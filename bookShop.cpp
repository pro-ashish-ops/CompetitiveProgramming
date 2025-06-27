#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> s(n+1); // prices
    vector<int> h(n+1); // pages
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= n; i++) cin >> h[i];

    vector<vector<int>> dp(n+1,vector<int>(x+1, 0));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0; // base case: zero cost, zero pages
    }
    for(int j = 0; j <= x; j++) {
        dp[0][j] = 0; // base case: zero books, zero pages
    }
    for(int i = 1; i <= n; i++) {
        for(int j = x; j >= 0; j--) {
            int pick = (j>= s[i]) ? dp[i-1][j-s[i]] + h[i] : 0; // if we can pick the i-th book
            int notPick = dp[i-1][j]; // if we do not pick the i-th book
            dp[i][j] = max(pick, notPick); // take the maximum of
        }
    }
    cout<< dp[n][x] << "\n"; // maximum pages we can get with budget x
    return 0;
}
