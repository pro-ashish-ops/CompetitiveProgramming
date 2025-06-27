#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    
    vector<ll> d(n);
    for(auto &i : d) cin >> i;
    sort(d.begin(), d.end());

    vector<ll> aval(m);
    for(auto &j : aval) cin >> j;
    sort(aval.begin(), aval.end());

    ll count = 0;
    ll i = 0, j = 0;

    while(i < m && j < n){
        if(abs(aval[i] - d[j]) <= k){
            count++;
            i++;
            j++;
        }
        else if(aval[i] < d[j] - k){
            i++;
        }
        else{
            j++;
        }
    }

    cout << count << "\n";
    return 0;
}
