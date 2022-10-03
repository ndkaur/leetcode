/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt =0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int pg=0;
        int ps=0;
        while(pg<g.size() && ps<s.size()){
            if(g[pg]<=s[ps]){
               pg++;
                ps++;
            }
            else 
                ps++;
        }
        return pg;
    }
};

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt =0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=0;
        int j=0;
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};
// @lc code=end


int main(){

    return 0;
}