#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    int window_size = 2;
    int count = 0;
    for (int i = 0; i < n - window_size + 1;i++)
    {
        string sub = s.substr(i, window_size);
        if(sub[0] == 'L' && sub[1] == 'R' or sub[0] == 'R' && sub[1] == 'L')
        {
            count++;
            i += window_size - 1; // Skip the next character to avoid overlapping
        }
        
    }
    cout << count << endl;

    return 0;
}