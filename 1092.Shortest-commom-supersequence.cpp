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

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n= str1.size();
        int m= str2.size();
        int dp[n+1][m+1];
        string res;

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(str1[i-1]==str2[j-1])
                    dp[i][j]= 1+ dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                res.push_back(str1[i-1]);
                i--; j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    res.push_back(str1[i-1]);
                    i--;
                }
                else{
                    res.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            res.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            res.push_back(str2[j-1]);
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};


class Solution {
public:
    string shortestCommonSupersequence(string& A, string& B) {
        int i = 0, j = 0;
        string res = "";
        for (char c : lcs(A, B)) {
            while (A[i] != c) // adding left char in string a
                res += A[i++];
            while (B[j] != c) // adding left character in string b
                res += B[j++];
            res += c, i++, j++;
        }
        return res + A.substr(i) + B.substr(j);
    }

    string lcs(string& A, string& B) {
        int n = A.size(), m = B.size();
        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (A[i] == B[j])
                    dp[i + 1][j + 1] = dp[i][j] + A[i];
                else
                    dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ?  dp[i + 1][j] : dp[i][j + 1];
        return dp[n][m];
    }
};

int main(){
    Solution sol;
    string s1="abac";
    string s2="cab";
    string len= sol.shortestCommonSupersequence(s1,s2);
    for(auto c:len)
        cout<<c;           
    return 0;
}