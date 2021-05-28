/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution0 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n= nums.size();
        vector<unsigned int> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(auto num:nums){
                if(num<=i)
                    dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n= nums.size();
        vector<unsigned int> dp(target+1,0);
        dp[0]=1;
        for(int i=0;i<=target;i++){
            if(!dp[i]) 
                continue;
            for(int num:nums){
                if(num+i<=target)
                    dp[i+num] += dp[i];
            }
        }
        return dp[target];
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2,3};
    int target = 4;
    int ans =sol.combinationSum4(nums,target);
    cout<<ans;
    return 0;
}