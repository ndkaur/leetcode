/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
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
    int findMaxConsecutiveOnes(vector<int>& nums){
        int n = nums.size();
        int count =0;
        int cnt=0;
        for(auto n:nums){
            if(n==1) 
                count = max(++cnt, count);
            else 
                cnt=0;
        }
        return count;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,0,1,1,0,1};
    int ans = sol.findMaxConsecutiveOnes(nums);
    cout<<ans;
    return 0;
}