/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
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

class Solution { //O(N)
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(auto token:tokens){ 
            if(token.size()>1 || isdigit(token[0]))
                stk.push(stoi(token));        
            else{ // when operator comes up
                auto b = stk.top();
                stk.pop() ;
                auto a= stk.top();
                stk.pop();
                if(token == "+")
                    stk.push(a+b);
                else if(token== "-")
                    stk.push(a-b);
                else if(token == "*")
                    stk.push(a*b);
                else 
                    stk.push(a/b);
            }
        }
        return stk.top();
    }
};

// @lc code=end


int main(){

    return 0;
}