#include <bits/stdc++.h>
using namespace std;

int comb(int n, int &res){
    if(n==0)return 1;
    res += comb(n-1, res);
    return res;
}

int main(){
    int n;
    cin>>n;
    int res = 0;
    cout<< comb(n, res);
    return 0;
}