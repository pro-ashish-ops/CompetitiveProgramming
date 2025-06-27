#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int,int>> duration, int n){
    sort(duration.begin(), duration.end());
    int ans =0, st =0;
    for(int i =0; i<n; i++){
        ans +=  duration[i].second - (duration[i].first+st);
        st += duration[i].first;
    }
    cout<< ans<<"\n";
    return 0;
}

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> duration(n);
        for(auto &it: duration){
            cin>> it.first>> it.second;
        }
        solve(duration, n);
    }
    return 0;
}