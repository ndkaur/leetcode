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

// conditions ->
// end up adding when open == close== n 
// can add open only when -> open < n
// can add close only when -> close < open 


// brute 

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", 2*n , ans);
        return ans;
    }
    void solve(string s, int N, vector<string>& ans){
        if(s.size() == N){ // len reached 
            if(valid(s)) // check if valid 
                ans.push_back(s); // then insert in ans
            return;
        }
        solve(s + '(' , N, ans); // try open case
        solve(s+')' , N, ans); // try close case
    }
    bool valid(string& s){
        int diff=0;
        for(auto& ch:s){
            diff += (ch =='(' ? 1 : -1);
            if(diff < 0)
                return false;
        }
        return diff==0;
    }
};


// optimised 
// time-> for each idx we try both brackets 2*2*2...2n times ->O(2^2n) = O(4^n)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        generate(n,0,0,temp, ans);
        return ans;
    }

    void generate(int n, int open , int close , string temp , vector<string>& ans){
        if(open == n && close == n)
            ans.push_back(temp); // cant exceed the given n size 
        else{
            if(open < n){ // can add more open parenthesis 
                generate(n, open+1, close, temp+'(' , ans);
            }
            if(close < open){
                generate(n, open, close+1, temp+')', ans);
            }
        }
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