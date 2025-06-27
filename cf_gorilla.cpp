#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i =0;i<n;i++){
        cin>> a[i];
    }
    sort(a.begin(),a.end());
    vector<int> count ={1};
    for(int i =1;i<n;i++){
        if(a[i] == a[i-1]){
            count.back()++;
        }
        else count.emplace_back(1);
    }
    sort(count.begin(),count.end());
        int i = 0;
        int ans = 0;
        while (i < count.size())
        {
            if (k > 0 and count[i] > 0)
            {
                if (k >= count[i])
                {
                    k -= count[i];
                    count[i] = 0;
                    // cout<<"k"<<k<<"\n";
                }else
                {
                    count[i] -= k;
                    k = 0;
                    // cout<<"k"<<k<<"\n";
                }
                i++;
            }else
            break;
        }
        for (int i = 0; i < count.size(); i++)
        {
            if (count[i] == 1)
            {
                ans++;
            }
            else if (count[i] > 1)
            {
                ans++;
            }
        }
        if(ans == 0){
            cout<<"1"<<"\n";
        }
        else{
            cout << ans << "\n";
        }

    }
    return 0;
}