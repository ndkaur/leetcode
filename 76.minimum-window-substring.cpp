/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
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
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(s==t)
            return s;
        if(n<m)
            return "";

        map<char,int>mp;
        for(auto c: t){
            mp[c]++;
        }
  
        int j = 0;
        int i = 0;
        int mn = INT_MAX;
        int start = 0;
        int sz = mp.size();

        while(j<n){
            if(mp.find(s[j])!=mp.end()){ // char of s exist in map of t
                mp[s[j]]--;
                // as the size of any elem becomes 0 the map size will also reduce
                if(mp[s[j]] == 0)
                    sz--;
            }
            // when map size became empty its time to slide the window 
            while(sz==0){
                // updating min len 
                if(j-i+1 < mn){
                    mn = j-i+1;
                    start = i; // starting of the substr 
                }
                // elemt exist in map so increase the cnt 
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    // new elem so increase map size
                    if(mp[s[i]]==1)
                        sz++;
                }
                i++;
            }
            j++;
        }
        if(mn == INT_MAX)
            return "";
        return s.substr(start,mn);
    }
};


// @lc code=end


int main(){

    return 0;
}