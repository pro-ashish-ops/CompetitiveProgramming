#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m + 1);
    for (int i = 0; i <= m; i++) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 0; i < m; i++) {
        if (__builtin_popcount(a[m] ^ a[i]) <= k) {
            res++;
        }
    }

    cout << res << "\n";
    return 0;
}
