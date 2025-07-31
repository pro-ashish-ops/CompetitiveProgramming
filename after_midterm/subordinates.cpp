#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 200001;
vector<int> adj[MAXN];


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    vector<bool> visited(MAXN, false);
    stack<pair<int, bool>> st; // {node, is_processed}
    vector<int> count(n+1, 0);

    st.push({1, false});

    while (!st.empty()) {
        auto [node, processed] = st.top();
        st.pop();

        if (processed) {
            for (auto child : adj[node]) {
                count[node] += count[child] + 1;
            }
        } else {
            st.push({node, true});
            for (auto child : adj[node]) {
                st.push({child, false});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << count[i] << " ";
    }

    return 0;
}
