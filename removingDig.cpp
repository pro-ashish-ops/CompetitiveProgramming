#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>> n;
    const int INF = 1e9;
    vector<int> cnt(n+1, INF);
    cnt[0] = 0;
    for(int i = 1; i<= n; i++){
        int temp = i;
        while(temp>0){
            cnt[i] = min(cnt[i], cnt[i - (temp % 10)] + 1);
            temp /= 10;
        }
    }
    cout<< cnt[n]<<'\n';
    return 0;
}