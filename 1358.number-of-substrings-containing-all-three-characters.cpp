/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
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
    int numberOfSubstrings(string s) {
        int n= s.size();
        int l= 0;
        int r=0;
        int cnt=0;
        unordered_map<char,int> mp;
        while(r<n){
            mp[s[r]]++;
            // valid case when all three elem present then good window 
            // so we can take up the next window 
            while(mp['a'] && mp['b'] && mp['c']){
                cnt += n-r;
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};
// @lc code=end


int main(){

    return 0;
}