#include <bits/stdc++.h>
using namespace std;

void pr_binary(int num){
    for(int i=10;i>=0;i--) cout<<((num>>i)&1);
    cout<<endl;
}

int main(){
    // for(char c='A';c<='Z';c++){
    //   cout<<c<<" ";
    //   pr_binary(int(c));
    // }
    // for(char c='a';c<='z';c++){
    //   cout<<c<<" ";
    //   pr_binary(int(c));
    // }
    int n=16;
   n&(n-1)?printf("NO"):printf("YES");
    return 0;
}