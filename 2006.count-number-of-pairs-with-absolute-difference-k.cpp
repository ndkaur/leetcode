/*
 * @lc app=leetcode id=2006 lang=cpp
 *
 * [2006] Count Number of Pairs With Absolute Difference K
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
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n= nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(nums[i]-nums[j])==k)
                    count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n= nums.size();
        int count=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]];
            if(mp[nums[i]+k]) 
                count+= mp[nums[i]+k];
            if(mp[nums[i]-k])
                count += mp[nums[i]-k];
            mp[nums[i]]++;
        }
        return count;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2,2,1};
    int k=1;
    int ans = sol.countKDifference(nums,k);
    cout<<ans;
    return 0;
}