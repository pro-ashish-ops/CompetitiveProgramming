#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first)
        return a.first < b.first;  // Ascending by first
    return a.second > b.second;   // Descending by second if first is same
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>> n;
    vector<pair<int,int>> jobs(n);
    for(int i = 0; i < n; i++) {
        int deadline, profit;
        cin >> deadline >> profit;
        jobs[i] = {deadline, profit}; // Store profit first for sorting
    }
    // sort jobs by deadline in ascending order and profit in descending order
    sort(jobs.begin(), jobs.end(),cmp);
    int profit = 0;
    int time = 0;
    for(int i = 0; i< n; i++){
        if(jobs[i].first > time){
            time++;
            profit += jobs[i].second;
        }
    }
    cout << profit << endl;
    return 0;
}