#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin>>n;
    vector<ll> vec(n);
    for(auto &i: vec){
        cin>> i;
    }
    ll i = 0;
    ll sum = -1000000000
;
    ll prevMax = -1000000000
;
    while(i<n){
        sum = max(vec[i], sum+ vec[i]);
        i++;
        prevMax = max(sum, prevMax);
    }
    cout<< prevMax;
    return 0;
}