/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
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
    int romanToInt(string s) {
        unordered_map<char, int> mp = { {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, 
                                       {'D',500}, {'M',1000}};
        
        int n= s.size();
        int ans =0;
        for(int i=0; i<n-1; i++){
            if(mp[s[i]] < mp[s[i+1]]){
               ans -= mp[s[i]];
            }
            else
                ans+= mp[s[i]];
        }
        return ans;
    }
};


// @lc code=end


int main(){

    return 0;
}