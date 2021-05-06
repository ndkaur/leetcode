/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
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
class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        int a =0,b=0,res=0;
        for(int i=0 ;i<n;i++){
            res =  max(a+nums[i],b);
            a=b;
            b=res;
        }
        return res;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={2,7,9,3,1};
    int ans = sol.rob(nums);
    cout<<ans;
    return 0;

}