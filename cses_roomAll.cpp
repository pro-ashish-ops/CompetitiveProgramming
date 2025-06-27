#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> customers; 

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        customers.push_back({a, b, i});
    }

    sort(customers.begin(), customers.end()); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> result(n);
    int room_count = 0;

    for (auto &[arr, dep, idx] : customers) {
        if (!pq.empty() && pq.top().first < arr) {
            int room = pq.top().second;
            pq.pop();
            pq.push({dep, room});
            result[idx] = room;
        } else {
            room_count++;
            pq.push({dep, room_count});
            result[idx] = room_count;
        }
    }

    cout << room_count << '\n';
    for (int x : result) cout << x << " ";
    cout << '\n';
}
