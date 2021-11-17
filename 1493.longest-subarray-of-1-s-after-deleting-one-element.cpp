/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
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
class Solution {
public:
    int longestSubarray(vector<int>& nums){
        int n= nums.size();
        vector<int> left(n), right(n);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            if(nums[i]==1)
                left[i]= left[i-1]+1;
            else 
                left[i]=0;
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]==1)
                right[i]=right[i+1]+1;
            else 
                right[i]= 0;
        }
        int ans = max(right[1], left[n-2]);
        for(int i=1;i<n-1;i++){
            ans = max(ans,right[i+1]+left[i-1]);
        }
        return ans;    
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,1,0,1};
    int ans = sol.longestSubarray(nums);
    cout<<ans;
   return 0;
}