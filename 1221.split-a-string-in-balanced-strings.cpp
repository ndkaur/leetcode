/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
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
    int balancedStringSplit(string s) {
        int n=s.size();
        int r=0;
        int l=0;
        int pair=0;
        for(char c:s){
            if(c=='R'){
                r++;
            }
            if(c=='L'){
                l++;
            }
            if(l==r)
                pair++;
        }
        return pair;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s="RLRRRLLRLL";
    int ans=sol.balancedStringSplit(s);
    cout<<ans;
    return 0;
}