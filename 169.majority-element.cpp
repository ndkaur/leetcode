/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
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
    int majorityElement(vector<int>& nums) {
        map<int,int> count;
        for(auto x:nums)
            count[x]++;
        int mx=0;
        for(auto p:count){
            mx=max(mx,p.second);
        }
        for(auto p:count){
            if(p.second==mx){
                return p.first;
            }
        }
        return -1;
    }
};
// @lc code=end



int main(){
    Solution sol;
    vector<int> nums={3,2,3};
    int ans=sol.majorityElement(nums);
    cout<<ans;
    return 0;
}