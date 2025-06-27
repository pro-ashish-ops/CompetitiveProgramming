#include <bits/stdc++.h>
using namespace std;

int solve(int x){
    if(x == 0) return 0;
    if(x == 1) return 1;
    long long count =0;
    for(long long i = 0; i< x; i++){
        if((1<<i) <= x){
            count++;
        }else{
            break;
        }
    }
    return 1+ solve(x- (1<< count-1));

}

int main(){
    long long x;
    cin>>x;
    cout<< solve(x);
    return 0;
}