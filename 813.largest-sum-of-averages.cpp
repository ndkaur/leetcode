/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
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
// class Solution0 {
// public:
//     double largestSumOfAverages(vector<int>& A, int k) {
//         int n = A.size();
//         vector<int> sum(n);
//         for(int i=0;i<n; i++){
//             sum[i] += A[i]+ (i>0 ? sum[i-1]:0);
//         }
//         return help(A,k,sum,0);
//     }
//     double help(vector<int>& A, int k, vector<int>& sum, int start){
//         int n = A.size();
//         if(k==1) // one pair ->average of A ->total sum/lenght -> sum= end - start + A[st]
//             return ((double) (sum[n-1]-sum[start]+A[start]) / (n-start)) ;
//         // k>1
//         double num=0;
//         for(int i=start ; i+k<=n; i++){
//             num = max(num, ((double)(sum[i]-sum[start]+A[start]) / (i-start+1) + help(A,k-1,sum,i+1)));
//             // i+1 one pair formed till i, next pair at i+1;
//         }
//         return num;
//     } // time limit exceeded 
// };

// TOP DOWN APPROACH 
class Solution1 {
public:
    double largestSumOfAverages(vector<int>& A, int k) {
        int n = A.size();
        vector<int> sum(n);
        for(int i=0;i<n;i++)
            sum[i] = A[i] + (i>0 ? sum[i-1]:0);
        vector<vector<double>> dp(n,vector<double>(k+1));
        return help(A,k,sum,dp,0);
    }
    double help(vector<int>& A , int k , vector<int>& sum, vector<vector<double>>& dp , int start){
        int n = A.size();
        if(dp[start][k]!=0) 
            return dp[start][k];
        if(k==1){
            dp[start][k] = ((double) (sum[n-1]-sum[start]+A[start]) / (n-start));
            return dp[start][k];
        }
        for(int i=start ; i+k<=n;i++){
            dp[start][k] = max(dp[start][k] , ((double)(sum[i]-sum[start]+A[start]) / (i-start+1) + help(A,k-1,sum,dp,i+1)));
        }
        return dp[start][k];
    }
};

// BOTTOM UP APPROACH 
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int k) {
        int n = A.size();
        vector<int> sum(n);
        for(int i=0;i<n;i++)
            sum[i] = A[i] + (i>0 ? sum[i-1]:0);
        vector<vector<double>> dp(n,vector<double>(k+1));

        for(int pairs=1;pairs<=k;pairs++){
            for(int start=0; start+pairs<=n; start++){
                if(pairs==1){
                    dp[start][pairs] = ((double) (sum[n-1]-sum[start]+A[start]) / (n-start));
                    continue;
                }
                for(int end = start; end+pairs<=n; end++){
                    dp[start][pairs] = max(dp[start][pairs] , ((double)(sum[end]-sum[start]+A[start]) / (end-start+1) + dp[end+1][pairs-1]));
                }
            }
        }
        return dp[0][k];
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> A={9,1,2,3,9};
    int k =3;
    int ans =sol.largestSumOfAverages(A,k);
    cout<<ans;
    return 0;
}