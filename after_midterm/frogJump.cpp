#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define INF 1e9

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    n = heights.size();
    vector<int> dp(n + 1, INF);
    dp[1] = heights[1] - heights[0];
    for (int i = 2; i < n; i++)
    {
        if (i - 1)
        {
            dp[i] = min(dp[i], abs(heights[i] - heights[i - 1]) + dp[i - 1]);
        }
        if (i - 2)
        {
            dp[i] = min(dp[i], abs(heights[i] - heights[i - 2]) + dp[i - 2]);
        }
    }
    cout << dp[n - 1];
    return 0;
}