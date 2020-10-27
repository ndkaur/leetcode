/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
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

// in general the numbers are 1 less then their index 
  // 0 1 2 3 4  (1-1=0)  num-1=idex  , idx =num-1 
 //  1 2 3 4 5  
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int idx = abs(nums[i])-1; // abs because we might have already visited that position 
            if(nums[idx]>0) 
                nums[idx]= -nums[idx]; // when we reach that value at idx we mark it negative 
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                ans.push_back(i+1);
        }
        return ans;
    }
};
// @lc code=end



int main(){
    Solution sol;
    vector<int> nums={4,3,2,7,8,2,3,1};
    vector<int> ans=sol.findDisappearedNumbers(nums);
    print(ans);
    return 0;
}