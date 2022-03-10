/*
 * @lc app=leetcode id=1941 lang=cpp
 *
 * [1941] Check if All Characters Have Equal Number of Occurrences
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
    bool areOccurrencesEqual(string s) {
        int n= s.size();
        map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        int cnt= mp[s[0]];
        for(auto & it:mp){
            if(cnt!=it.second)
                return false;
        }
        return true;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s= "abacbc";
    bool ans= sol.areOccurrencesEqual(s);
    cout<<ans;
    return 0;
}