/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
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

// 1,3,4,5  n= 7   so new cut becomes -> insert 0 and len at front and last respectively 
//  0  1 3 4 5  7 
    // i     j 
// let us do partition at 3 
// 0 1 3         3 4 5 7
// len=0-3=3     len = 7-3=4    3 4 5 6 7
// i,j is at 1    i at 4 and j at 5  

//  recursion  time - exponential
class Solution0 {
public:
    int f(int i, int j, vector<int>& cuts){
        if(i>j) return 0;
        int mn= INT_MAX;
        for(int idx=i;idx<=j;idx++){
            int cost = cuts[j+1] -cuts[i-1] + f(i,idx-1,cuts)+f(idx+1,j,cuts);
            mn= min(mn, cost);
        }
        return mn ;
    }
    int minCost(int n, vector<int>& cuts) {
        int len= cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return f(1,len,cuts);
    }
};

//  memoization  // time -> M*M *M   space  M*M + M
class Solution1 {
public:
    int f(int i, int j, vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j) return 0;
        int mn= INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int idx=i;idx<=j;idx++){
            int cost = cuts[j+1] -cuts[i-1] + f(i,idx-1,cuts,dp)+f(idx+1,j,cuts,dp);
            mn= min(mn, cost);
        }
        return dp[i][j]= mn ;
    }
    int minCost(int n, vector<int>& cuts) {
        int len= cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(len+1,vector<int>(len+1,-1));
        return f(1,len,cuts,dp);
    }
};

//  tabulation  time m^3   space N^2
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int len= cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(len+2,vector<int>(len+2,0));
        
        dp[len+1][len+1]=0;

        for(int i=len;i>=1;i--){
            for(int j=1;j<=len;j++){
                if(i>j) continue;
                int mn= INT_MAX;
                for(int idx=i;idx<=j;idx++){
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][idx-1] + dp[idx+1][j];
                    mn= min(mn, cost);
                }
                dp[i][j]= mn;
            }
        }

        return dp[1][len];
    }
};


// @lc code=end


int main(){
    Solution sol;
    int n=7;
    vector<int> cuts={1,3,4,5};
    int ans = sol.minCost(n,cuts);
    cout<<ans;
    return 0;
}

// .......................................................................................................

// MATRIX CHAIN MULTIPLICATION 

// int f(int i, int j, vector<int>& arr,vector<vector<int>>& dp){
// 	if(i==j) return 0;
// 	int mn=1e9;
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	for(int k=i;k<j;k++){
// 		int steps= arr[i-1]* arr[k]* arr[j] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
// 		if(steps< mn) 
// 			mn= steps;
// 	}
// 	return dp[i][j]=mn;
// }
// int matrixMultiplication(vector<int> &arr, int n){
// 	vector<vector<int>>dp(n, vector<int>(n,-1));
//     return f(1,n-1,arr,dp);
// }


// int matrixMultiplication(vector<int> &arr, int n){
// 	vector<vector<int>>dp(n, vector<int>(n,0));
	
// 	for(int i=1;i<n;i++) 
// 		dp[i][i]=0;
	
// 	for(int i=n-1; i>=0; i--){
// 		for(int j=i+1; j<n; j++){
// 			int mn=1e9;
// 			for(int k=i;k<j;k++){
// 				int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k]+ dp[k+1][j];
// 				if(steps< mn) mn= steps; 
// 			}
// 			dp[i][j]= mn;
// 		}
// 	}
//     return dp[1][n-1];
// }


// ..............................................................................................................