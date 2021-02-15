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
        int n= s.size();
        int m = t.size();
        if(n!=m) return false;
        map<char,char> count;
        for(int i=0;i<n;i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        for(auto c:count){
            if(c.second)
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