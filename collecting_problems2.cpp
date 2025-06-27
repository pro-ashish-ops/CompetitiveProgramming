#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> pos(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int rounds = 1;
    while(m--){
        int x ,y;
        cin>> x>>y;
        --x,--y;
        swap(a[x], a[y]);
        pos[a[x]] = x;
        pos[a[y]] = y;
        for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) {
            rounds++;
        }
    }
        cout<<rounds<<"\n";
        rounds =1;
    }
    return 0;
}
