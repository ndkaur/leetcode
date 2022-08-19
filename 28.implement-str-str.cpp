/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
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
    int strStr(string hay, string needle) {
        int h= hay.size();
        int n= needle.size();
       
        for(int i=0; i<=h-n; i++){
            int j=0;
            for(;j<n; j++){
                if(hay[i+j] != needle[j]){ // if not equal , always compare the full len toll j
                    break;
                }
            }
            if(j==n) // if j reached last means whole string exist in hay 
                return i;
        }
        return -1;
    }
};

// @lc code=end


int main(){
    Solution sol;
    string hay="hello";
    string needle= "ll";
    int ans = sol.strStr(hay, needle);
    cout<< ans;
    return 0;
}