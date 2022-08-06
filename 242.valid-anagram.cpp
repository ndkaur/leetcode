/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
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
    bool isAnagram(string s, string t) {
        if(s==t) return true;
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto itr:mp){
            if(itr.second)
                return false;
        }
        return true;
    }
};

// @lc code=end


int main(){
    Solution sol;
    string s ="rat";
    string t= "tar";
    bool ans=sol.isAnagram(s,t);
    cout<<ans;
    return 0;
}