/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
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
    int characterReplacement(string s, int k) {
        int n= s.size();
        int l=0;
        int r=0;
        int len=0;
        int mx=0;
        map<char,int> mp; 
        while(r<n){
            mp[s[r]]++;
            mx= max(mx,mp[s[r]]); // find the mx frequency 
            // window len - mx freq <=k for valid window
            if((r-l+1) - mx > k ){ // invalid window
                mp[s[l]]--;
                l++;
            }
            len = max(len , (r-l+1));
            r++;
        }
        return len;
    }
};


class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        int len=0;
        int maxf= 0; // max frequency 
        unordered_map<int ,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            maxf = max( maxf,mp[s[i]]);
            if(len - maxf < k) // valid 
                len++;
            else 
                mp[s[i-len]]--;
        }
        return len;
    }
};

// @lc code=end


int main(){

    return 0;
}