/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */
#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        int n= nums.size();
        int val1= help(nums,f,s);
        int val2= help(nums,s,f);
        return max(val1,val2);
    }
    int help(vector<int>&nums, int f, int s){
        int n= nums.size();
        vector<int> dp1(n,0) , dp2(n,0);
        int sum1=0;
        // finding for the first len 
        for(int i=0;i<n;i++){
            if(i<f){
                sum1+=nums[i];
                dp1[i]= sum1;
            }else{
                sum1+= nums[i]-nums[i-f];
                dp1[i] = max(sum1, dp1[i-1]);
            }
        }
        // finding for the second len
        int sum2=0;
        for(int i=n-1;i>=0;i--){
            if(i+s>=n){
                sum2+= nums[i];
                dp2[i] = sum2;
            }else{
                sum2+= nums[i]-nums[i+s];
                dp2[i]= max(sum2, dp2[i+1]);
            }
        }
        int ans =0;
        for(int i=f-1;i<n-s;i++){
            ans= max(ans,dp1[i]+dp2[i+1]);
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={0,6,5,2,2,5,1,9,4};
    int f= 1;
    int s=2;
    int ans = sol.maxSumTwoNoOverlap(nums,f,s);
    cout<<ans;
    return 0;
}