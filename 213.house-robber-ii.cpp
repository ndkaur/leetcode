/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
// 100  1 100  1  1  100   sum=100
class Solution {
public:
    int rob(vector<int>& nums) {
       int n =nums.size();
       if(nums.empty()) return 0;
       if(n==1) return nums[0];

       vector<int> numsA(nums.begin(),nums.end()-1);
       vector<int> numsB(nums.begin()+1,nums.end());

       return max(rb(numsA),rb(numsB)); 
    }
    int rb(vector<int>&nums){
        int a=0,b=0,res=0;

        for(int i=0;i<nums.size();i++){
            res=max(a+nums[i],b);
            a=b;
            b=res;
        }
        return res;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2,3,1};
    int ans=sol.rob(nums);
    cout<<ans;
    return 0;
}