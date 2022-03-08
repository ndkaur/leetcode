/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
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
    int numIdenticalPairs(vector<int>& nums) {
        int n= nums.size();
        int count=0;
        unordered_map<int,int> mp;
        for(int n:nums){
            count+= mp[n]++;
        }
        return count;
    }
};


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n= nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j])
                    count++;
            }
        }
        return count;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,1,1,1};
    int ans= sol.numIdenticalPairs(nums);
    cout<<ans;
    return 0;
}