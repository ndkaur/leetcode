/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
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
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n != m)
            return false;
        if(s == goal)
            return true;
        while(m--) {
            if(s == goal)
                return true;
            s = s.substr(1) + s[0];
        }
        return false;
    }
};

// @lc code=end


int main(){

    return 0;
}