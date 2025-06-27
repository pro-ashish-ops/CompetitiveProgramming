#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int ans = 0;
    while(n> 0){
        if(n%2 == 1){
            ans += 1;
            n -= (n/2 +1);
        }else if(n == 4){
            ans += n/2;
            n -= (n/2 +1);
        }
        else if(n!= 4 and n%4 == 0){
            ans +=1;
            n = n-2;
        }
        else{
            ans += n/2;
            n -= (n/2 +1);
        }
    }
    cout << ans<< "\n";
}

int main(){
    int tc;
    cin>> tc;
    while(tc--){
        solve();
    }
    return 0;
}