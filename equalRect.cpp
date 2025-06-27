#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
		cin >> n;
		vector<int> a(4 * n);
		for (int j = 0; j < 4 * n; ++j) {
			cin >> a[j];
		}
		sort(a.begin(), a.end());
		int area = a[0] * a.back();
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			int lf = i * 2, rg = 4 * n - (i * 2) - 1;
			if (a[lf] != a[lf + 1] || a[rg] != a[rg - 1] || a[lf] * 1ll * a[rg] != area) {
				ok = false;
			}
		}
		if (ok) cout << "YES" <<"\n";
		else cout << "NO" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin>> tc;
    while(tc--){
        solve();
    }
    return 0;
}