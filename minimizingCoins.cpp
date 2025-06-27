#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
     cin>> n >> x;
    vector<int> coins(n);   
    for(auto &coin : coins){
        cin>> coin;
    }   
    vector<int> count(x+1,0);
    const int INF = 1e9; // A large value to represent infinity
    count[0] = 0; // Base case: 0 coins needed to make sum of 0
    for(int i = 1; i<= x; i++){
        count[i] = INF; // Initialize to a large value
        for(auto &c : coins){
            if(i - c >= 0){
                count[i] = min(count[i], count[i - c] + 1);
            }
        }
    }
    cout << (count[x] == INF ? -1 : count[x]) << "\n";
    return 0;
}