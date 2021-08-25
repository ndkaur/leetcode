/*
 * @lc app=leetcode id=1638 lang=cpp
 *
 * [1638] Count Substrings That Differ by One Character
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
    int countSubstrings(string s, string t) {
        int n= s.size();
        int m = t.size();
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                for(int k=0;k+i<n && k+j<m;k++){
                    if(s[i+k]!= t[j+k] && ++count>1)
                        break;
                    ans += count;
                }
            }
        }
        return ans;
    }
};  // o(n3)


class Solution1 {
public:
    int countSubstrings(string s, string t) {
        int ans =0;
        for(int i=0;i<s.length();i++)
            ans+= help(s,t,i,0);
        for(int j=1;j<t.length();j++)
            ans+= help(s,t,0,j);
        return ans;
    }
    int help(string& s, string& t, int i, int j){
        int cur=0,prev=0,ans=0;
        for(int n =s.length(),m=t.length();i<n && j<m;++i,++j){
            cur++;
            if(s[i]!=t[j]){
                prev= cur;
                cur=0;
            }
            ans += prev;
        }
        return ans;
    }
}; // o(mn)

class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size();
        int m = t.size();
        int ans =0;
        int dpl[101][101]={},dpr[101][101]={};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dpl[i][j] = 1+dpl[i-1][j-1];  
            }
        }
        for(int i=n;i>0;i--){
            for(int j=m;j>0;j--){
                if(s[i-1]==t[j-1])
                    dpr[i-1][j-1]=1+ dpr[i][j]; 
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i]!=t[j])
                    ans += (dpl[i][j]+1) * (dpr[i+1][j+1]+1);
            }
        }
        return ans;
    }
}; 




// @lc code=end


int main(){
    Solution sol;
    string s ="ab";
    string t = "bb";
    int ans = sol.countSubstrings(s,t);
    cout<<ans;
    return 0;
}