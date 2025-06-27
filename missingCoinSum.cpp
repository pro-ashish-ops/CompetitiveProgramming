#include <bits/stdc++.h>
using namespace std;

bool findMissingSum(int target, vector<int>coin){
    int j =0;
    while(target>=0 && target<= coin[j]){
        if(target>= coin[j]){
            target -= coin[j];
            j++;
        }
        if(target == 0){
            return true;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> coin(n);
    for (auto &i : coin)
    {
        cin >> i;
    }
    int target = 1;
    int sum = accumulate(coin.begin(), coin.end(), 0);
    int i =1;
    int j =0;
    while(i< sum){
    while(target>=0 && target>=coin[j]){
        if(target>= coin[j]){
            target -= coin[j];
            j++;
        }
        if(target == 0){
            i++;
        }
        if(target<coin[j]){
            
        }
    }
    if(target != 0){
        j++;
    }
    }
}
