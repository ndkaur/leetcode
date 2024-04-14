/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
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
    void solve(int idx, string temp, set<string>& st, vector<string>& ans, string& s){
        int n = s.size();
        if(idx==n){
            // removing the space from behind that we added after the word found in the set 
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        // we need a complete string 
        string curr = "";
        for(int i=idx; i<n; i++){
            // adding the curr word
            curr += s[i];
            if(st.find(curr)!=st.end()){
                // one word found add space cause we want a sentence 
                curr += ' ';
                // temp is used to keep the sentence formation 
                solve(i+1, temp+curr, st, ans, s);
                // backtracking if words cant be made
                curr.pop_back();
            }
        }
        return; 
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> st(wordDict.begin(), wordDict.end());
        // backtracking , ans 
        vector<string> ans;
        // temp is used to keep the sentence formation 
        solve(0, "", st, ans, s);
        return ans;
    }
};

// @lc code=end


int main(){
    Solution sol;
    string s="catsanddog";
    vector<string> wordDict={"cat","cats","and","sand","dog"};
    vector<string> result=sol.wordBreak(s,wordDict);
    for(auto s:result){
        cout<<s<<"";
        cout<<endl;
    }
    return 0;
}