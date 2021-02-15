/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
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
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        string store;
        vector<vector<char>> table (2,vector<char>());
        table.push_back(vector<char>{'a','b','c'}); // 2
        table.push_back(vector<char>{'d','e','f'}); // 3
        table.push_back(vector<char>{'g','h','i'});  // 4
        table.push_back(vector<char>{'j','k','l'});  // 5
        table.push_back(vector<char>{'m','n','o'});  // 6
        table.push_back(vector<char>{'p','q','r','s'});  // 7 
        table.push_back(vector<char>{'t','u','v'});   // 8
        table.push_back(vector<char>{'w','x','y','z'}); // 9

        backtracking(table,ans,store,0,digits);
        return ans;
    }
    void backtracking(const vector<vector<char>>& table,vector<string> &ans,string &store,int index,string &digits){
        if(index==digits.size()) // size 0 or each element from digits is visited
            ans.push_back(store);
        else{
            for(int i=0;i<table[digits[index]-'0'].size();i++){
                store.push_back(table[digits[index]-'0'][i]);
                backtracking(table,ans,store,index+1,digits);
                store.pop_back();
            }
        }
    }
};
// @lc code=end


int main(){
    Solution sol;
    string digits="23";
    vector<string>ans ;
    ans=sol.letterCombinations(digits);
    for(auto c:ans){
        cout<<c<<endl;
    }
    return 0;
}