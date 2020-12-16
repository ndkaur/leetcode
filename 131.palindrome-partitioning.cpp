/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curlist;
        dfs(s,ans,curlist,0);
        return ans;
    }
    void dfs(string& s,vector<vector<string>>&ans,vector<string> &curlist,int start){
        int n=s.size();
        if(start >= n){ 
            ans.push_back(curlist);
            return;
        }
        for(int end=start;end<n;end++){
            if(is_palindrome(s,start,end)){
                curlist.push_back(s.substr(start,end-start+1));
                dfs(s,ans,curlist,end+1);
                curlist.pop_back();
            }
        }
    }
    bool is_palindrome(string& s,int left,int right){
        while(left<right){
            if(s[left++]!=s[right--]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end


int main(){
    
    return 0;
}