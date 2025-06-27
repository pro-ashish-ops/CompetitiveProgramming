#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>coins(n);
    for(auto &it: coins){
        cin>>it;
    }
    sort(coins.begin(), coins.end());

    int sum = 0;
    for(int i =0; i< n; i++){
        sum += coins[i];
    }
    int count = 0, prevSum =0;
    int nextSum = 0;
    int i = coins.size()-1;
    while(i>=0){
        prevSum += coins[i];
        nextSum = sum - prevSum;
        if(prevSum > nextSum){
            count++;
            break;
        }
        count++;
        i--;
    }
    cout<< count;
    return 0;
}