#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int mod = 1e9 + 7;
    int tc;
    cin>> tc;
    while(tc--){
        int n, k;
        cin>>n>> k;
        ll num = (1LL << k) - 1;
        ll count = __builtin_popcountll(num);
        cout<< "count: " << count << "\n";
        cout<< mod_pow(n,count,mod)<< "\n";
    }
    return 0;
}