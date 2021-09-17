/*
 * @lc app=leetcode id=1690 lang=cpp
 *
 * [1690] Stone Game VII
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
    int stoneGameVII(vector<int>& stones) {
        int n= stones.size();
        vector<int> sum(n+1,0);
        for(int i=0;i<n;i++){
            sum[i+1]= sum[i]+stones[i];
        }
        return help(0,n-1,stones,sum);
    }
    int help(int i, int j, vector<int>& stones, vector<int>&sum){
        if(i>j) return 0;
        // max(left remove remain sum  , right remove)
        return max(sum[j+1]-sum[i+1]-help(i+1,j,stones,sum), sum[j]-sum[i]-help(i,j-1,stones,sum));
    } // time limit exceeded
};

class Solution1 {
public:
    int stoneGameVII(vector<int>& stones) {
        int n= stones.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        vector<int> sum(n+1,0);
        for(int i=0;i<n;i++){
            sum[i+1]= sum[i]+stones[i];
        }
        return help(0,n-1,stones,sum,dp);
    }
    int help(int i, int j, vector<int>& stones, vector<int>&sum,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        // max(left remove remain sum  , right remove)
        return dp[i][j]=max(sum[j+1]-sum[i+1]-help(i+1,j,stones,sum,dp), sum[j]-sum[i]-help(i,j-1,stones,sum,dp));
    }
}; // o (n2)

class Solution {
public:
    int stoneGameVII(vector<int>& s) {
        int n= s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        return help(0,n-1,s, accumulate(begin(s),end(s),0),dp);
    }
    int help(int i, int j, vector<int>& s, int sum,vector<vector<int>>& dp){
        if(i==j) return 0;
        return dp[i][j] ? dp[i][j] : dp[i][j] = max(sum-s[i]-help(i+1,j,s,sum-s[i],dp) , sum-s[j]-help(i,j-1,s,sum-s[j],dp));
    }
    
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> arr={5,3,1,4,2};
    int ans =sol.stoneGameVII(arr);
    cout<<ans;
   return 0;
}