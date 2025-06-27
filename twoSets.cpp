#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int sum = n * (n + 1) / 4;
    const int mod = 1e9 + 7;
    vector<int> dp(sum + 1, 0);
    dp[0] = 1; // base case: one way to make sum
    if (n * (n + 1) / 2 % 2 != 0 || n < 2)
    {
        cout << 0 << "\n"; // if n is odd or less than 2, no valid partition
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= i; j--)
        {
            dp[j] = (dp[j] + dp[j - i]) % mod; // update the number of ways to make sum j
        }
    }
    int inv2 = 500000004; // precomputed inverse of 2 modulo 1e9+7
    cout << (1LL * dp[sum] * inv2) % mod << "\n";

    return 0;
}