/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
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
    bool canConstruct(string ran, string mag) {
        vector<int> cnt(26);
        for( char ch: mag)
            cnt[ch - 'a']++;
        for(char ch: ran){
            if(cnt[ch-'a']-- <=0) 
                return false;
        }
        return true;
    }
};


class Solution { //O(N)
public:
    bool canConstruct(string ran, string mag) {
       map<char,int> mp;
        for(char ch: mag){
            mp[ch]++;
        }
        for(auto ch:ran){
            if(mp[ch]>0)
                mp[ch]--;
            else 
                return false;
        }
        return true;
    }
};
// @lc code=end


int main(){

    return 0;
}