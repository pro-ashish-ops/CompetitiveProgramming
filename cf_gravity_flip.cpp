#include <bits/stdc++.h>
using namespace std;

// int solve(vector<int> &conf, int n){
//     int i =0;
//     while(i< n){
//         if(i+1 < n and conf[i]>conf[i+1]){
//             int diff= conf[i]- conf[i+1];
//             conf[i] -= diff;
//             conf[i+1] += diff;
//             i++;
//         }else{
//         i++;
//         }
//     }
//     for(auto &it: conf){
//         cout<< it<<"\n";
//     }
//     return 0;
// }

int main(){
    int n;
    cin>>n;
    vector<int> conf(n);
    for(auto &it: conf){
        cin>> it;
    }
    sort(conf.begin(), conf.end());
    // solve(conf,n);
    for(auto &it: conf){
        cout<< it<<" ";
    }
    return 0;
}