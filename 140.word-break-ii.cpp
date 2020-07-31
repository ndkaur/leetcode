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
    unordered_map<string,vector<string>> count;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(count.find(s) != count.end()) 
            return count[s];
        vector<string> result;
        for(string w:wordDict){
            if(s.substr(0,w.length())==w){
                if(w.length()==s.length())
                    result.push_back(w);
                else{
                    vector<string> temp=wordBreak(s.substr(w.length()),wordDict);
                    for(string t:temp){
                        result.push_back(w+" "+t);
                    }
                }
            }
        }
        count[s]=result;
        return result;
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