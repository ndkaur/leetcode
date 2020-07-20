/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<s.length() && j<t.length()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else 
                j++;
        }
        if(i==s.length())
            return true;
        else 
            return false;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s="abc";
    string t="ahbgd";
    bool out=sol.isSubsequence(s,t);
    cout<<out;
    return 0;
}