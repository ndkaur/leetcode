/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
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
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).substr(1, 2*s.size()-2).find(s) != -1 ;
        
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s="aba";
    bool ans=sol.repeatedSubstringPattern(s);
    cout<<ans;
    return 0;
}