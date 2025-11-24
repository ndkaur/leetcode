/*
 * @lc app=leetcode id=2035 lang=cpp
 *
 * [2035] Partition Array Into Two Arrays to Minimize Sum Difference
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

// WRONG ANSWER DOESNOT WORK FOR NEGATIVE TEST CASES

// similar to subset sum equal to target 

// bool f(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){
// 	if(target==0) return true;
// 	if(idx==0){
// 		return (arr[0]== target);
// 	}
// 	if(dp[idx][target]!=-1) return dp[idx][target];
// 	bool notTake = f(idx-1 , target,arr,dp);
// 	bool take= false;
// 	if(arr[idx]<=target)  take = f(idx-1, target-arr[idx],arr,dp);
// 	return dp[idx][target]= take | notTake;
// }

// bool subsetSumToK(int n, int k, vector<int> &arr) {
// 	vector<vector<bool>> dp(n, vector<bool>(k+1,0));
//     for(int i=0;i<n;i++) dp[i][0]= true;
// 	if(arr[0]<=k) dp[0][arr[0]]= true;
// 	for(int i=1;i<n;i++){
// 		for(int target=1;target<=k;target++){
// 			bool notTake= dp[i-1][target];
// 			bool take = false;
// 			if(arr[i]<= target)
// 				take = dp[i-1][target- arr[i]];
// 			dp[i][target] = take | notTake;
// 		}
// 	}
// 	return dp[n-1][k];
// }

// bool subsetSumToK(int n, int k, vector<int> &arr) {
// 	vector<bool> prev(k+1,0);
// 	vector<bool> curr(k+1,0);
// 	prev[0]= curr[0] = true;
// 	prev[arr[0]]= true;
// 	for(int i=1;i<n;i++){
// 		for(int target=1;target<=k;target++){
// 			bool notTake= prev[target];
// 			bool take = false;
// 			if(arr[i]<= target)
// 				take = prev[target- arr[i]];
// 			curr[target] = take | notTake;
// 		}
// 		prev= curr;
// 	}
// 	return prev[k];
// }



// @lc code=start

// @lc code=end
// its not gonna work , the algo to be used here must be meet in the middle 
// i= sum and j= n
// class Solution {
// public:
//     int minimumDifference(vector<int>& nums) {
//         int n= nums.size();
//         int sum = 0;
//         for(int num:nums){
//             sum+= num;
//         }
        
//         vector<vector<bool>> dp(sum+1, vector<bool>(n+1,0));
//         for(int j=0; j<=n; j++){
//             dp[0][j] = 1;
//         }

//         for(int i=1; i<=sum; i++){
//             dp[i][0] =0;
//         }

//         for(int i=1; i<=sum; i++){
//             for(int j=1; j<=n; j++){
//                 dp[i][j] = dp[i][j-1];

//                 if(i >= nums[j-1])
//                     dp[i][j] = dp[i][j] || dp[i-nums[j-1]][j-1];
//             }
//         }
//         int ans=INT_MAX;
//         for(int i=sum/2; i>=0; i--){
//             if(dp[i][n]==1){
//                 // int s1= i;
//                 // int s2= sum-s1;
//                 // ans = min(ans, abs(s1-s2));
//                 ans = sum - 2*i;
//                 break;
//             }
//         }
//         return ans;
//     }
// };

// // i-> n  and j = sum
// class Solution {
// public:
//     int minimumDifference(vector<int>& nums) {
//         int n= nums.size();
//         int sum = 0;
//         for(int num:nums){
//             sum+= num;
//         }
        
//        vector<vector<bool>> dp(n+1, vector<bool>(sum+1,0));
//         for(int i=0; i<=n; i++){
//             dp[i][0] = 1;
//         }
        
//         for(int j=1; j<=sum; j++){
//             dp[0][j] = 0;
//         }
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=sum; j++){
//                 dp[i][j] = dp[i-1][j];

//                 if(nums[i-1] <= j)
//                     dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
//             }
//         }
//         int ans = INT_MAX;
//         for(int j=sum/2; j>=0; j--){
//             if(dp[n][j]== true){
//                 // int s1= i;
//                 // int s2= sum-s1;
//                 // ans = min(ans, abs(s1-s2));
//                 ans = sum - 2*j;
//                 break;
//             }
//         }
//         return ans;
//     }
// };




int main(){
    Solution sol;
    vector<int> nums={3,9,7,3};
    int ans = sol.minimumDifference(nums);
    cout<<ans;
    return 0;
}