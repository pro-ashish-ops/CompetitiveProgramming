#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >>n;
    vector<int> v(n);
    for(int i =0; i<n-1; i++){
        cin>> v[i];
    }
    sort(v.begin(), v.end());
    int i =0;
    while(true){
        if(v[i+1]-v[i] != 1){
            cout<< v[i]+1;
            break;
        }
        i++;
    }
    return 0;
}