#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n+1, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; i++)
        if (x[0] == 0 or x[0] == i)
            dp[1][i] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i-1] != 0 and x[i-1] != j){
                dp[i][j] = 0;
                continue;
            }
            for (int prev = j - 1; prev <= j + 1; prev++)
            {
                if (prev < 1 or prev > m)
                    continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][prev]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp[n][i]) % mod;
    cout << ans << endl;
    return 0;
}