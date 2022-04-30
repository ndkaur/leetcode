/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
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
//  find the lcs , fill the dp array 
//  when the value of dp[i]  gets same increase the count 
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int mx=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]> nums[j] && dp[j]+1> dp[i]){
                    dp[i]= dp[j]+1;
                    count[i] = count[j]; // diff value of dp so same count
                }
                else if(nums[i]> nums[j] && dp[j]+1 == dp[i]){
                    count[i] += count[j];
                }
            }
            mx= max(mx, dp[i]); // mx = length of lis 
        }
        // check if max of dp values exist more than one times 
        //  then just sum up all those occurences 
        int times= 0;
        for(int i=0;i<n;i++){
            if(dp[i]==mx)
                times+= count[i];
        }
        return times;
    }
};

//        1  3  5  4  7
// dp =   1  2  3  3  4
// cnt =  1  1  1  1  2 
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,3,5,4,7};
    int ans= sol.findNumberOfLIS(nums);
    cout<<ans;
    return 0;
}