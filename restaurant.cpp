#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> dept(n);
    for(int i =0; i<n;i++){
        cin>> arr[i]>> dept[i];
    }
    sort(arr.begin(), arr.end());
    sort(dept.begin(), dept.end());
    int count = 1;
    int maxCount = 1;
    int i = 1, j= 0;
    while(i<n && j< n){
        if(arr[i] < dept[j]){
            count++;
            maxCount = max(count, maxCount);
            i++;
        }else{
            maxCount = max(count, maxCount);
            count--;
            j++;
        }
    }
    cout<< maxCount<< "\n";
    return 0;
}