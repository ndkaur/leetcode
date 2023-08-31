/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
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
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

class Solution0 { //O(n)  //O(n)
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        stk.push(-1);
        int ans =0;

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                stk.push(i);
            }
            else {
                if(stk.size()==1){ // only invalid idx persent 
                    stk.top() = i; // invalid number of first 
                }
                else { // the close bracket found
                    stk.pop();
                    // ans = the number of idx btw the current and the invalid one 
                    ans = max(ans, i-stk.top());
                }
            }
        }
        return ans;
    }
};


class Solution { //O(n)  //O(1)
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int cnt =0;
        int invalid =-1;
        int ans =0;

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                cnt++;
            }
            else {
                if(cnt==0){
                    invalid =i ; // invalid number of first 
                }
                else { // the close bracket found
                    cnt--;
                    if(cnt==0){ // a pair of brackets is formed
                        ans = max(ans, i-invalid);
                    }
                }
            }
        }

        // from other side
        cnt =0;
        invalid = n;
        for(int i=n-1; i>=0; i--){
            if(s[i]==')'){
                cnt++;
            }
            else {
                if(cnt==0)
                    invalid = i;
                else{
                    cnt--;
                    if(cnt==0)
                        ans = max(ans, invalid-i);
                }
            }
        }

        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}