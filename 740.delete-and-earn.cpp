/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
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
class Solution { // runtime error 
public:
    int deleteAndEarn(vector<int>& nums) {
        int n= nums.size();
        vector<int> values(n+1,0);
        for(int num:nums)
            values[num] += num;
        int take =0, skip=0;
        for(int i=0;i<n;i++){
            int takei= skip+values[i];
            int skipi= max(skip,take);
            take = takei;
            skip = skipi; 
        }
        return max(take,skip);
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={2,2,3,3,3,4};
    int ans =sol.deleteAndEarn(nums);
    cout<<ans;
    return 0;
}