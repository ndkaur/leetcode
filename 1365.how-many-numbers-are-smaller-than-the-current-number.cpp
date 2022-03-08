/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution0 {
public:
    vector<int> smaller(vector<int>& nums) {
        int len=nums.size();
        vector<int> result;
        for (int i=0;i<len;i++){
            int count=0;
            for(int j=0;j<len;j++){
                if(nums[j]<nums[i])
                    count++;
            }
            result.push_back(count);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> smaller(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> mp;
        vector<int> sorted= nums;
        sort(sorted.begin(),sorted.end());
        for(int i=n-1;i>=0;i--){
            mp[sorted[i]]=i;
        }
        for(int i=0;i<n;i++){
            nums[i]= mp[nums[i]];
        }
        return nums;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vi nums,result;
    nums={6,5,8,4};
    result=sol.smaller(nums);
    print(result);
    return 0;
} 