/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
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
    bool isAlienSorted(vector<string>& words, string order) {
        int n = order.size();
        unordered_map<char,int> mp;
        for(int i=0; i<n; i++){
            mp[order[i]] = i+1; // allot each char a number in incr order
        }

        for(int i=0; i<words.size()-1; i++){
            bool ans = check(words[i], words[i+1], mp);
            if(ans == false)
                return false;
        }
        return true;
    }

    bool check(string word1 , string word2, unordered_map<char,int>& mp){
        int n = min(word1.size(), word2.size());
        for(int i=0; i<n; i++){
            if(mp[word1[i]] < mp[word2[i]])
                return true;
            else if( mp[word1[i]] > mp[word2[i]]) 
                return false;
        }

        if(word1.size() > word2.size())
            return false;
        return true;
    }
};
// @lc code=end


int main(){

    return 0;
}