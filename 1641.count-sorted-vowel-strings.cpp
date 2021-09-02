    /*
 * @lc app=leetcode id=1641 lang=cpp
 *
 * [1641] Count Sorted Vowel Strings
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
class Solution0 {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5,1);
        for(int i=2;i<=n;i++){
            for(int k=3;k>=0;k--){
                dp[k]=dp[k]+dp[k+1];
            }
        }
        int ans =0;
        for(auto d:dp) 
            ans+= d;
        return ans;
    }
};


class Solution1 {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(6));
        for(int i=1;i<=n;i++){
            for(int k=1;k<=5;k++){
                dp[i][k] = dp[i][k-1]+ (i>1? dp[i-1][k]:1);
            }
        }
        return dp[n][5];
    }
};


class Solution2 {
public:
    int countVowelStrings(int n) {
        vector<int> dp={0,1,1,1,1,1};
        for(int i=1;i<=n;i++){
            for(int k=1;k<=5;k++){
                dp[k]+= dp[k-1];
            }
        }
       return dp[5];
    }
};

class Solution {
public:
    int countVowelStrings(int n) {
      return (n+1)*(n+2)*(n+3)*(n+4)/24;       
    }
};

// [ 0 1 1 1 1 1]
// [ 0 1 2 3 4 5 ]
// [ 0 1 3 6 10 15 ]  dp[k]= dp[k]+dp[k-1]

// n=1  1  1  1  1  1 
// n=2  5  4  3  2  1
//n=3   15 10 6  3  1 

// sum of next line number is actually sum of 
// previous two terms 


// @lc code=end


int main(){
    Solution sol;
    int n=2;
    int ans = sol.countVowelStrings(n);
    cout<<ans;
    return 0;
}