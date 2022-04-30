/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
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
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

//  we can solve this using the lis , just sort the array and change the divisiblity condition 
class Solution {   // time  O(n*n) +O(n)    space O(n) 
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;
        vector<int> dp(n+1,1);
        vector<int> hash(n);

        sort(nums.begin(), nums.end());

        int lastIdx=0;
        int mx=1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]% nums[j]==0 && dp[i]< dp[j]+1){
                    dp[i]= dp[j]+1;
                    hash[i]= j;
                }
            }
            if(dp[i]> mx){
                mx= dp[i];
                lastIdx =i;
            }
        }
        ans.push_back(nums[lastIdx]);
        while(hash[lastIdx]!= lastIdx){
            lastIdx = hash[lastIdx];
            ans.push_back(nums[lastIdx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end


int main(){ 
    Solution sol;
    vector<int> nums={1,2,3};
    vector<int> ans= sol.largestDivisibleSubset(nums);
    print(ans);
    return 0;
}