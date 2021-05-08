/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        int mx=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j]= dp[i-1][j-1]+1;
                    if(mx<dp[i][j]) 
                        mx= dp[i][j];
                }
            }
        }
        return mx;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums1={1,2,3,2,1};
    vector<int> nums2={3,2,1,4,7};
    int ans = sol.findLength(nums1,nums2);
    cout<<ans;
    return 0;
}