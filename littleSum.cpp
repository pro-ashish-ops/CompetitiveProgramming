
#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back
 
using namespace std;
using li = long long;
 
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, q;
    cin >> n >> q;
 
    vector <int> a(n), add(n + 1);
 
    for(int i = 0; i < n; i++)
        cin >> a[i];
 
    while(q--)
    {
        int l, r;
        cin >> l >> r;
 
        l--;
 
        add[l]++;
        add[r]--;
    }
 
    for(int i = 1; i < n; i++)
        add[i] += add[i - 1];
 
    sort(a.begin(), a.end());
    sort(add.begin(), add.end() - 1);
 
    li ans = 0;
 
    for(int i = 0; i < n; i++)
        ans += a[i] * 1ll * add[i];
 
    cout << ans;
}