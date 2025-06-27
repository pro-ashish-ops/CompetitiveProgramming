#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct range{
    int l, r, index;
    bool operator < (const range &other) const
    {
        if( l == other.l)
            return r > other.r;
        return l< other.l;
        
    }
};
int main(){
    int n;
    cin>>n;
    vector<range> ranges(n);
    vector<bool> contained(n);
    vector<bool> contains(n);
    for(int i = 0; i< n; i++){
        cin>> ranges[i].l;
        cin>> ranges[i].r;
        ranges[i].index = i;
    }
    sort(ranges.begin(),ranges.end());
    int maxEnd = 0;
    for(int i =0; i< n; i++){
        if(ranges[i].r <= maxEnd)
            contained[ranges[i].index] = true;
        maxEnd = max(maxEnd, ranges[i].r);
    }
    int minEnd = INT32_MAX;
    for(int i = n-1; i >= 0; i--){
        if(ranges[i].r >= minEnd)
            contains[ranges[i].index] = true;
        minEnd = min(minEnd, ranges[i].r);
    }
    for(int i =0; i< n; i++){
        cout<< contains[i]<<" ";
    }
    cout<< "\n";
    for(int i =0; i< n; i++){
        cout<<contained[i]<< " ";
    }
    cout<<"\n";
    return 0;
}