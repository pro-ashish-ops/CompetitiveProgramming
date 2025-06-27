#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;
    vector<int> count(n+1, 0);
    count[0] = 1; // Base case: one way to roll a sum of 0 with no dice
    for(int i = 1; i<=n ; i++){
        for(int j = 1; j<= 6; j++){
            if(i-j >= 0){
                count[i] += count[i-j];
                count[i] %= 1000000007; // To prevent overflow  
            } 
        }
    }
    cout << count[n]<< "\n";
    return 0;
}