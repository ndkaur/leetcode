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
class Solution {
public:
    int minimumDifference(vector<int>& arr) {
        int n= arr.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum += arr[i];
        }
        int k= totalSum;
        // subset sum the dp table is filled we will use it to check if value sum can be possible or not
        vector<vector<bool>> dp(n, vector<bool>(k+1,0));
        // base case target ==0 return true
        for(int i=0;i<n;i++) 
            dp[i][0]= true;
        // answer reached case
        if(arr[0]<=k) dp[0][arr[0]]=true;

        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool notTake = dp[i-1][target];
                bool take = false;
                if(arr[i]<=target)  take=dp[i-1][target-arr[i]];
                dp[i][target] = take | notTake; // dp table is filled till here 
            }
        }
        // dp[n-1][target-> 1.....toatlsum] to check if true or not
        int mini=1e9;
        for(int s1=0; s1<= totalSum/2; s1++){
            if(dp[n-1][s1]== true)
                mini = min(mini,abs(s1-(totalSum-s1)));
        }
        return mini;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={3,9,7,3};
    int ans = sol.minimumDifference(nums);
    cout<<ans;
    return 0;
}