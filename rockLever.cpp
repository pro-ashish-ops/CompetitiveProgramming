#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int64_t ans = 0;
        for (int j = 29; j >= 0; j--)
        {
            int64_t cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] >= (1 << j) && a[i] < (1 << (j + 1)))
                {
                    cnt++;
                }
            }
            ans += cnt * (cnt - 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}