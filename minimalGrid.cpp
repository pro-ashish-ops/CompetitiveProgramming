#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<string>> dp(n, vector<string>(n));
    dp[0][0] = string(1, grid[0][0]);

    for (int j = 1; j < n; j++)
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {   
            dp[i][j] = 'a';
            if (i)
            {
                dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j]);
            }
            if (j)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
    }

    vector<char> ans;
    int i = n - 1, j = n - 1;
    while (i > 0 || j > 0)
    {
        ans.push_back(grid[i][j]);
        if (i > 0 && j > 0)
        {
            if (dp[i - 1][j] < dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        else if (i > 0)
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    ans.push_back(grid[0][0]);
    reverse(ans.begin(), ans.end());
    for (char c : ans)
    {
        cout << c;
    }
    return 0;
}