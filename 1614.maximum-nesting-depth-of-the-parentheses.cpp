/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
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

class Solution {
public:
    int maxDepth(string s) {
        int open =0;
        int mx =0;
        for(auto ch:s){
            if(ch == '('){
                open++;
                mx = max(mx, open);
            }
            if(ch == ')')
                open--;
        }
        return mx;
    }
};


class Solution {
public:
    int maxDepth(string s) {
        int open =0;
        int mx =0;
        for(auto ch:s){
            if(ch == '('){
                open++;
               
            }
            if(ch == ')'){
                mx = max(mx, open);
                open--;
            }
        }
        return mx;
    }
};

// @lc code=end



int main(){

    return 0;
}