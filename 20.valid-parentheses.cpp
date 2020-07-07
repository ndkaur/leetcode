/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
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
    bool isValid(string s) {
        stack<char> stk;
        for(auto c:s){
            if(c=='(' || c=='{' || c=='['){
                stk.push(c);
            }
            else{
                if(stk.empty())
                    return false;
                if(c==')' && stk.top()!='(')
                    return false;
                if(c=='}' && stk.top()!='{')
                    return false;
                if(c==']' && stk.top()!='[')
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s="(}";
    bool out=sol.isValid(s);
    cout<<out;
    return 0;
}