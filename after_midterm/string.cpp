#include <bits/stdc++.h>
using namespace std;
int my_count = 0;
    void helper(vector<int>& nums, int k,int sum, int idx){
        if( idx == nums.size()){
            if(sum == k){
                my_count++;
            }
            return;
        }
        // helper(nums, k, sum + nums[idx], idx+1);
        if(sum + nums[idx] <= k){
            helper(nums, k, sum + nums[idx], idx);
        }
        helper(nums, k, sum, idx+1);

    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
        //your code goes here
        my_count = 0;
        helper(nums, k, 0, 0);
        return my_count;
    }

int main() {
	// your code goes here
	int n;
	cin>>n;
    vector<int> nums(n);
    for(int i =0; i< n; i++){
        int a;
        cin>> a;
        nums[i] =a;
    }
    int k;
    cin>> k;
    cout<< countSubsequenceWithTargetSum(nums,k);
}
