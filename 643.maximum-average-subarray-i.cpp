/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum=0, sumax=0;
        double avg;
        for(int i=0;i<k;i++){
            sum=sum+nums[i];
            sumax=sumax+nums[i];
            
        }
        for(int i=k;i<n;i++){
            sum =sum-nums[i-k];
            sum=sum+nums[i];
            sumax=max(sum,sumax);
            
        }
        avg= sumax/k;
        return avg;

    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,12,-5,-6,50,3};
    int k=4;
    double avg=sol.findMaxAverage(nums,k);
    cout<<avg;
    return 0;
}