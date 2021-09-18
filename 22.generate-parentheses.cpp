/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
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
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        help(ans, "",n,0);
        return ans;
    } // m is closing brackets 
    void help(vector<string>&ans, string str,int n, int m){
        if(n==0 && m==0){
            ans.push_back(str);
            return ;
        }
        if(m>0) help(ans, str+")",n,m-1);
        if(n>0) help(ans,str+"(",n-1,m+1);
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n=3;
    vector<string> ans =sol.generateParenthesis(n);
    for(auto x:ans)
        cout<<x<<endl;
   return 0;
}