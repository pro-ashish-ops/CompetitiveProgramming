#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;           
    cin >> n >> x;
    vector<int> coins(n);   
    for(auto &coin : coins){
        cin >> coin;
    }
    vector<int> count(x + 1, 0);
    const int MOD = 1e9 + 7; // To prevent overflow
    count[0] = 1; // Base case: one way to make sum of 0
    for(auto c: coins){
        for(int i = 1; i<= x; i++){
            if(i-c >= 0){
                count[i] += count[i - c];
                count[i] %= MOD; // To prevent overflow
            }
        }
    }
    cout << count[x] << "\n"; // Output the number of ways to make sum x    
    return 0;
}