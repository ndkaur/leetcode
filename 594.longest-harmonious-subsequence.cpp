/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
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
    int findLHS(vector<int>& nums) {
        int n= nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int count =0;
            bool check = false;
            for(int j=0;j<n;j++){
                if(nums[j]==nums[i])
                    count++; // but the check is still false so res will not change 
                else if (nums[j]+1==nums[i]){
                    count++;
                    check =true;
                }
            }
            if(check)
                res= max(count,res);
        }
        return res;
    }
};      
// @lc code=end

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int prev_count=1;
        for(int i=0;i<n;i++){
            int count=1;
            if(i>0 && nums[i]-nums[i-1]==1){
                // repeating
                while(i<n-1 && nums[i]==nums[i+1]){
                    count++;
                    i++;
                }
                ans=max(ans,(count+prev_count));
                prev_count=count;
            }
            else{
                // if repeating from beginging
                while(i<n-1 && nums[i]==nums[i+1]){
                    count++;
                    i++;
                }
                prev_count=count;
            }
        }
        return ans;
    }
};  


int main(){
    Solution sol;
    vector<int> nums={1,3,2,2,5,2,3,7};
    int ans=sol.findLHS(nums);
    cout<<ans;
    return 0;
}