/*
 * @lc app=leetcode id=1208 lang=cpp
 *
 * [1208] Get Equal Substrings Within Budget
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
    int equalSubstring(string s, string t, int maxCost) {
        int  n = s.size();
        int m = t.size();
        int i =0;
        int j =0;
        int mx = 0;
        int cost =0;
        while(j<n){
            cost += abs(t[j] - s[j]);
            
            while(cost > maxCost){
                cost -= abs(s[i]-t[i]);
                i++;
            }
            mx = max(mx, j-i+1);
            j++;
        }
        return mx;
    }
};

// @lc code=end


int main(){

    return 0;
}