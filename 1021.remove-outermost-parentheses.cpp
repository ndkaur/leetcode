/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    string removeOuterParentheses(string S) {
        int n = S.size();
        string ans;
        int previous_balance =0;
        for(auto c:S){
            if(previous_balance==1){
                if(c=='('){ //so that the last bracket doesnot get included;
                    ans=ans+c;
                }
            }
            else if(previous_balance>1){
                ans=ans+c;
            }
            previous_balance=previous_balance+(c=='('?1:-1); // c=( bal=bal+1;

        }
        return ans;
    }
};
// @lc code=end
int main(){
    Solution sol;
    string S="(()())(())(()(()))";
    string ans=sol.removeOuterParentheses(S);
    cout<<ans;
    return 0;
}

