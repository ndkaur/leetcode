/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
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
class Solution0 {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
       
        int j=n-1, i=0;
        int count=0;
        while(i<j){
            if(nums[i]+nums[j]==k){
                count++;
                i++;
                j--;
            }
            else if(nums[i]+nums[j]>k)
                j--;
            else 
                i++;
        }
        return count;
        
    }
};

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int> mp;
        int count=0;
        for(int num:nums){
            int required= k-num;
            if(mp[required]>0){
                count++;
                mp[required]--;
            }
            else 
                mp[num]++;
        }
        return count;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2,3,4};
    int k= 5;
    int ans= sol.maxOperations(nums, k);
    cout<<ans;
    return 0;
}