#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    unordered_map<int, vector<int>> pos;

    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    int sasha = 0, dima = 0;
    long long total = 0;

    for (int i = 1; i <= n; i++) {
        int x = pos[i][0];
        int y = pos[i][1];

        int opt1 = abs(sasha - x) + abs(dima - y);
        int opt2 = abs(sasha - y) + abs(dima - x);

        if (opt1 <= opt2) {
            total += opt1;
            sasha = x;
            dima = y;
        } else {
            total += opt2;
            sasha = y;
            dima = x;
        }
    }

    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
        solve();
    return 0;
}
