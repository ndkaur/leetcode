/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
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

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k){
        int n= s.size();
        if(n==0 || k>n)
            return 0;
        if(k==0)
            return n;
        map<char,int> count;
        for(int i=0;i<n;i++){
            count[s[i]]++;
        }
        int idx=0;
        while(idx<n && count[s[idx]]>=k)
            idx++;
        if(idx==n)
            return n;
        int left = longestSubstring(s.substr(0,idx),k);
        int right = longestSubstring(s.substr(idx+1),k);
        return max(left,right);
    }
};
// @lc code=end

int main(){
    Solution sol;
    string s="ababbc";
    int k=2;
    int ans= sol.longestSubstring(s,k);
    cout<<ans;
    return 0;
}