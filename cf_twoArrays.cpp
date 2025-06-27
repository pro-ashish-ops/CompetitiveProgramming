#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, vector<int> &b, int k, int n)
{
    int i = 0, j = 0;
    int count = 1;
    while (i < n and j < n and count <= k)
    {
        if (a[i] < b[j])
        {
            swap(a[i], b[j]);
            j++;
            count++;
            i++;
        }
        else
        {
            j++;
        }
    }
    int sum = 0;
    for (auto &it : a)
    {
        sum += it;
    }
    cout << sum<< "\n";
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for (auto &it : a)
        {
            cin >> it;
        }
        for (auto &it : b)
        {
            cin >> it;
        }
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        solve(a, b, k, n);
    }
    return 0;
}