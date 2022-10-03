/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
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

// we always check for the remaining balance
class Solution {
public:
    bool checkValidString(string s) {
        stack<char> stk;
        int open =0;
        int close =0;
        int star =0;
        for(int i=0; i<s.size(); i++){
            // remaining balance for open will increase when i == '('
            if(s[i] == '(' ){
                open++;
            }else  // not an opwn can be a * or ) so balance decrease 
                open--;
            // balance of close will decrese if i is a '*' or ')' 
            if(s[i] != ')') // balance increase if it is a open bracket 
                close++;
            else // if it is a close bracket ')'
                close--;
            // close can never get negative 
            if(close < 0)
                break;
            // open may/can aquire a negative value 
            open =  max(open,0);
        }
        return open ==0;
    }
};
// @lc code=end



int main(){

    return 0;
}