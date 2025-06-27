#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> last_index;
    int ans = INT32_MAX;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (last_index.count(a[i])) {
            ans = min(ans, i - last_index[a[i]] + 1);
        }
        last_index[a[i]] = i;
    }

    if (ans == INT32_MAX)
        cout << -1 << "\n"; // No duplicate found
    else
        cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
