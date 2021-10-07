/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start
class Solution0 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;
        unordered_map<int,int> cnt;
        for(auto x:nums)
            cnt[x]++;
        for(auto itr:cnt){
            if(itr.second==2)
                ans.push_back(itr.first);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return {};
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
        return ans;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={4,3,2,7,8,2,3,1};
    vector<int> ans = sol.findDuplicates(nums);
    print(ans);
   return 0;
}


//      4 3 2 7 8 2 3 1
//i=0  nums[0]-1 = 4-1=3  nums[3]=7  
//     4 3 2 -7 8 2 3 1
//i=1  nums[nums[1]-1] nums[3-1] = nums[2] =2 
//     4 3 -2 -7 8 2 3 1
// i=2   nums[nums[2]-1] =nums[1]=3
//     4 -3 -2 -7 8 2 3 1
// i=3  nums[nums[3]-1] = nums[7-1]=nums[6] = 3 
//     4 -3 -2 -7 8 2 -3 1
//  i=4  nums[nums[4]-1] = nums[7]=1
//    4 -3 -2 -7 8 2 -3 -1 
// i=5  nums[nums[5]-1] = nums[1]= 3  -> already negative 
 // so pb in ans