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
    bool wordBreak(string s, vector<string>& wd) {
        int n= wd.size();
        int m= s.size();
        if(n==0) return false;
        vector<bool>dp(m+1,false);
        dp[0]=true;
        for(int i=1;i<=m;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    string word = s.substr(j,i-j); // taking char and finding if present 
                    if(find(wd.begin(),wd.end(),word)!=wd.end()){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[m];
    }
};


int main(){
    Solution sol;
    string s="leetcode";
    vector<string> worddict= {"leet","code"};
    bool ans = sol.wordBreak(s,worddict);
    cout<<ans;
    return 0;
}