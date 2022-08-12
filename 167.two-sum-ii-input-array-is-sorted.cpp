/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
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

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}
// @lc code=start
class Solution { //O(N)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> out;
        int l=0,r=n-1;
        while(l<r){
            if(nums[l]+nums[r]==target){
                out.push_back(l+1);// zero based indexing so +1
                out.push_back(r+1);
                return out;
            }
            else if(nums[l]+nums[r]>target)
                r--;
            else 
                l++;
        }
        return out;
    }
};

class Solution { //O(N)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int dif= target - nums[i];
            if(mp.count(dif)){
                ans.push_back(mp[dif]+1);
                ans.push_back(i+1);
                
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};
// @lc code=end



int main(){
    Solution sol;
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> out=sol.twoSum(nums,target);
    print(out);
    return 0;
}