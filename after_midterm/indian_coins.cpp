#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int amount;
    cin>> amount;
    int count = 0;
    sort(coins.rbegin(), coins.rend()); // Sort coins in descending order
    int i = 0;
    while(amount>0 and i<n){
        if(coins[i]<= amount){
            count++;
            amount -= coins[i];
        }else{
            i++;
        }
    }
    cout<< count << endl;

    return 0;
}