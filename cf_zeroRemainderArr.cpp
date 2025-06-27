#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(vector<ll> &array, ll k)
{
    map<ll, ll> count;
    for (auto &it : array)
    {
        if (it % k != 0)
        {
            ll inc = k - it % k;
            count[inc]++;
        }
    }
    ll ans = 0;
    for(auto [inc, c]: count){
        ll moves = (c-1)*k + inc +1;
        ans = max(ans, moves);
    }
    cout<< ans <<"\n";
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> array(n);
        for (auto &it : array)
        {
            cin >> it;
        }
        solve(array, k);
    }
    return 0;
}