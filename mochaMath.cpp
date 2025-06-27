#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{   
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
        int res = a[0];
        for (int i = 1; i < n; i++)
        {
            res = res & a[i];
        }
        cout<< res << "\n";
    }
    return 0;
}