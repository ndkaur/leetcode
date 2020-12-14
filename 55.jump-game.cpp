/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
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
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i=0; // simple movement in the array 
        for(int reach=0;i<n && i<=reach;i++){ // reach is how far it can move 
           reach = max(i+nums[i],reach); 
        }
        return i==n;// if i reached at last position without getting terminated inbetween 
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={2,3,1,1,4};
    bool ans= sol.canJump(nums);
    cout<<ans;
    return 0;
}