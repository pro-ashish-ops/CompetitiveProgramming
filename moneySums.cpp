#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    vector<bool> dp(sum + 1, false);
    dp[0] = true; // zero sum is always possible
    for(int coin:a){
        for(int j = sum; j >= coin; j--){
            if(dp[j - coin]){
                dp[j] = true; // if we can make j-coin, we can make j
            }
        }   
    }
    cout << count(dp.begin()+1, dp.end(), true) << "\n";
// print the number of distinct sums that can be formed
    for(int i = 1; i <= sum; i++) {
        if (dp[i]) {
            cout << i <<" "; // print the maximum sum that can be formed
        }
    }
    return 0;
}