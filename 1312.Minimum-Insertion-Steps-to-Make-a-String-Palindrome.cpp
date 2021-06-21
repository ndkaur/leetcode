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
    int minInsertions(string s) {
        int n= s.size();
        string a =s;
        reverse(a.begin(),a.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==a[j-1])
                    dp[i][j] = 1+ dp[i-1][j-1];
                else 
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return n-dp[n][n];
    }
};

class Solution {
public: 
    int minInsertions(string s) {
        int n= s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i+1][j+1] = s[i]==s[n-1-j] ? 1+ dp[i][j] : max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return n-dp[n][n];
    }
};


int main(){
    Solution sol;
    string s="zaz";
    int ans = sol.minInsertions(s);
    cout<<ans;
    return 0;
}