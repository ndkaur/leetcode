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

class Solution0 {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int len =2;
        map<int , map<int,int>> dp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int diff= nums[j]-nums[i];
                dp[diff][j] = dp[diff].count(i) ? dp[diff][i]+1 : 2;
                len= max(len,dp[diff][j]);
            }
        }
        return len;
    }
}; // time limit exceeded 


class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int len =2;
        vector<vector<int>> dp(n,vector<int>(2000,0));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff= nums[j]-nums[i]+1000;
                dp[j][diff] = max(2,dp[i][diff]+1);
                len = max(len, dp[j][diff]);
            }
        }
        return len;
    }
}; 



int main(){
   Solution sol;
   vector<int> nums= {3,6,9,12};
   int ans  = sol.longestArithSeqLength(nums);
   cout<<ans;
}