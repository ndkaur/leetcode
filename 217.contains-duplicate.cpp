/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
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
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> count;
        for(auto i:nums){
            count[i]++;
        }
        for(auto itr:count){
            if(itr.second >= 2) 
                return true;
        }
        return false;
    }
};
// @lc code=end



int main(){
    Solution sol;
    vector<int> nums={1,2,3,1,1,1,2,3,4,5};
    bool ans=sol.containsDuplicate(nums);
    cout<<ans;
    return 0;
}