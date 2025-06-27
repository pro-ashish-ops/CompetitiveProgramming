#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i<= n; i++){
        dp[i][0] = 0; // empty subsequence of b
    }
    for(int j = 0; j <= m; j++){
        dp[0][j] = 0; // empty subsequence of a
    }   
    // vector<int> ans;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // ans.push_back(a[i - 1]); // store the common element
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
        if(a[i - 1] == b[j - 1]){
            dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

// Now reconstruct the LCS
vector<int> ans;
int i = n, j = m;
while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) {
        ans.push_back(a[i - 1]);
        i--, j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1]) {
        i--;
    }
    else {
        j--;
    }
}
reverse(ans.begin(), ans.end()); // Because we backtracked
cout<< ans.size() << "\n"; // Print the length of the LCS
for (int x : ans) {
    cout << x << " ";
}
cout << "\n";
    return 0;
}