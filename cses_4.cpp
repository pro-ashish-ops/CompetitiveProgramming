#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll diff = 0;
    ll prev= v[0];
    for (ll i = 0; i <n; i++)
    {
        if (v[i] < prev)
        {
            diff += prev - v[i];
        }
        else{
            prev = v[i];
        }
    }
    cout << diff;
    return 0;
}