#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, m;
int tilings[1001][(1<<10)]; 

void fill_column(int j, int idx, int curr_mask, int next_mask){
    if(idx == n){
        tilings[j+1][next_mask] = (tilings[j+1][next_mask] + tilings[j][curr_mask]) % MOD;
        return;
    }
    if((curr_mask & (1<< idx))){
        fill_column(j, idx + 1, curr_mask, next_mask); 
    }else{
        fill_column(j, idx + 1, curr_mask, next_mask | (1<<idx)); 
        if(idx + 1 < n && !(curr_mask & (1 << (idx + 1)))){ 
            fill_column(j, idx + 2, curr_mask, next_mask);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    tilings[0][0] = 1;
    for(int j = 0; j<m; j++){
        for(int mask = 0; mask< (1<<n); mask++){
            if(tilings[j][mask]> 0)
                fill_column(j,0, mask, 0);
        }
    }
    cout<< tilings[m][0];

    return 0;
}