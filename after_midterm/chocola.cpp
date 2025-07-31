#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n-1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m-1; i++) {
        cin >> b[i];
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int i = 0, j = 0, cost = 0;
    int hpieces =1, vpieces = 1;
    while (i < n-1 && j < m-1) {
        if(a[i] >= b[j]){
            cost += a[i] * vpieces;
            hpieces++;
            i++;
        } else {
            cost += b[j] * hpieces;
            vpieces++;
            j++;
        }
    }
    while (i < n-1) {
        cost += a[i] * vpieces;
        hpieces++;
        i++;
    }
    while (j < m-1) {
        cost += b[j] * hpieces;
        vpieces++;
        j++;
    }
    cout << cost << endl;

    return 0;
}