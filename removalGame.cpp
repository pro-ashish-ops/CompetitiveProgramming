#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll, 2> ar;
  int n;
const int mxn = 5e3;
    ar dp[mxn][mxn];
    int a[mxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = n - 1; ~i; --i)
    {
        for (int j = i; j < n; j++)
        {
            ar tr;
            if (i == j)
            {
                tr = {a[i], 0};
            }
            else
            {
                if (dp[i + 1][j][1] + a[i] > dp[i][j - 1][1] + a[j])
                {
                    tr = {dp[i + 1][j][1] + a[i], dp[i + 1][j][0]};
                }
                else
                {
                    tr = {dp[i][j - 1][1] + a[j], dp[i][j - 1][0]};
                }
            }
            dp[i][j] = tr;
        }
    }
    cout << dp[0][n - 1][0] << "\n";
    return 0;
}