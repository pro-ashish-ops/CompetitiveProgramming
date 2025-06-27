#include <bits/stdc++.h>
using namespace std;

int solve(int &a, int b, int mod){
    if(b == 0) return 1;
    long long res = solve(a, b / 2, mod);
    res = (res * res) % mod;
    if(b % 2 == 1) res = (res * a) % mod;
    return res;
}

int main(){
    int tc;
    cin>> tc;
    while(tc--){
        int a, b;
        cin>> a >> b;
        int mod = 1e9 + 7;
        cout<< solve(a, b, mod) << "\n";
    }
    return 0;
}

