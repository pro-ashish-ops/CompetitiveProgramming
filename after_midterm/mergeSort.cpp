#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

vector<int> merge(vector<int>& left, vector<int>& right){
    vector<int> res;
    int i = 0, j = 0;
    while(i< left.size() and j < right.size()){
        if(left[i] <= right[j]){
            res.push_back(left[i++]);
        }
        else{
            res.push_back(right[j++]);
        }
    }
    while(i< left.size()) res.push_back(left[i++]);
    while(j < right.size()) res.push_back(right[j++]);
    return res;
}

vector<int> mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) return arr;

    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {8,5,3,4,1};
    vector<int> res = mergeSort(arr);
    for(auto it: res) cout<< it<<" ";

    return 0;
}