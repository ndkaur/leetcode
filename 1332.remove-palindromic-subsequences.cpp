/*
 * @lc app=leetcode id=1332 lang=cpp
 *
 * [1332] Remove Palindromic Subsequences
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=startt5
class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        if(s=="")
            return 0;
        for(int i=0,j=n-1; i<j; i++,j--){
            if(s[i]!=s[j])
                return 2;
        }
        return 1;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s ="baabb";
    int ans = sol.removePalindromeSub(s);
    cout<< ans;
    return 0;
}