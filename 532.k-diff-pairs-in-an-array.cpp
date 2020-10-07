/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
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
    int findPairs(vector<int>& nums, int k) {
        int n= nums.size();
        map<int,int> m;
        if(k<0) return 0;
        for(auto x:nums) m[x]++;
        int count=0;
        for(auto itr:m){
            if((!k && itr.second>1) || (k && m.count(itr.first+k)))
                count++;
        }
        return count;
    }
};
// @lc code=end



int main(){
    Solution sol;
    vector<int> nums={1,3,1,5,4};
    int k=0;
    int ans= sol.findPairs(nums,k);
    cout<<ans;
    return 0;
}