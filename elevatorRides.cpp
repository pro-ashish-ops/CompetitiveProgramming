#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    int n,x;
    cin >> n >> x;
    vector<int> w(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<pair<int, int>> dp(1<<n, {1e9, 1e9}); // dp[i] = {max rides, min time}
    dp[0] = {1, 0}; // base case: no rides, no time
    for(int i = 0; i < (1<<n); i++) {
        for(int bit = 0; bit < n; bit++) {
            if((1<<bit)&i){
                int space_taken = dp[i^(1<<bit)].second;
                if(space_taken + w[bit] <= x) {
                    dp[i] = min(dp[i], {dp[i^(1<<bit)].first, space_taken + w[bit]}); // update with current ride
                } else {
                   dp[i] = min(dp[i], {dp[i^(1<<bit)].first + 1, w[bit]}); // new ride needed
                }
            }
        }
    }
    cout<< dp[(1<<n) - 1].first << "\n"; // print the minimum number of rides needed

    return 0;
}