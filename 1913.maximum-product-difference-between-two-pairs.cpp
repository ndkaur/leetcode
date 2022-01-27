/*
 * @lc app=leetcode id=1913 lang=cpp
 *
 * [1913] Maximum Product Difference Between Two Pairs
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
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int ans =0;
        int p1= nums[0]*nums[1];
        int p2= nums[n-2]*nums[n-1];
        ans = p2-p1;
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={5,6,2,7,4};
    int ans = sol.maxProductDifference(nums);
    cout<<ans;
    return 0;
}