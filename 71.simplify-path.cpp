/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
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
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> stk;
        string ans;
        for(int i=0; i<n; i++){
            if(path[i]== '/')
                continue;
            string temp; 
            // till we does not find the ending back slash
            while(i<n && path[i] != '/'){
                temp += path[i];
                i++;
            }
            if(temp == ".")
                continue;
            else if(temp == ".."){
                if(!stk.empty())
                    stk.pop();
            }
            else 
                stk.push(temp);
        }
        // adding stk elem to ans
        while(stk.size()){
            // adding values of stack top at back of string ans
            ans = "/" + stk.top()+ans;
            stk.pop();
        }
        if(ans.size()==0)
            return "/";
        
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}