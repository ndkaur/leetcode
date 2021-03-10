/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
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
class Solution0 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;
        int dup=-1;
        int mis=-1;
        for(int i=1;i<=n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[j]==i)
                    count++;
            }
            if(count==2)
                dup=i;
            else if(count==0)
                mis=i;
        }
        ans.push_back(dup);
        ans.push_back(mis);
        return ans;
    }  // O(n^2)
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int dup=-1;
        int mis=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])
                dup=nums[i];
            else if(nums[i]>nums[i-1]+1)
                mis=nums[i-1]+1;
        }
        ans.push_back(dup);
        ans.push_back(nums[n-1]!= n ? n:mis);
        return ans;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2,2,4};
    vector<int> ans=sol.findErrorNums(nums);
    print(ans);
    return 0;
}