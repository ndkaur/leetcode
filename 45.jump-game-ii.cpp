/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
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
    int jump(vector<int>& nums) {
        int n= nums.size();
        int start=0;
        int end=0;
        int step=0;
        while(end < n-1){
            step++;
            int maxend = end+1;
            for(int i=start;i<=end;i++){
                if(i+nums[i]>=n-1)// enough steps available to reach
                    return step;
                maxend =max(maxend ,i+nums[i] );
            }
            start=end;
            end=maxend;
        }
        return step;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={2,3,0,1,4};
    int ans= sol.jump(nums);
    return ans;
    return 0;
}