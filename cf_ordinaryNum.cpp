#include <iostream>
using namespace std;

int solve(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i / 10 == 0)
        {
            count++;
        }
        else{
            if(i%(i%10) == 0){
                count++;
            }
        }
    }
    cout<< count<<"\n";
    return 0;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> n;
        solve(n);
    }
}