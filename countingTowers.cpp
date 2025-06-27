#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
vector<vector<int>> dp(1e6 + 1, vector<int>(2));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        dp[n][0] = 1;
        dp[n][1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            dp[i][0] = (2ll * dp[i + 1][0] + dp[i + 1][1]) % MOD;
            dp[i][1] = (4ll * dp[i + 1][1] + dp[i + 1][0]) % MOD;
        }
        cout << (dp[0][0] + dp[0][1]) % MOD << '\n';
    }
    return 0;
}
