/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
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
    int maximumWealth(vector<vector<int>>& ac) {
        int mx=0;
        for(int i=0;i<ac.size();i++){
            int ans=0;
            for(int j=0;j<ac[0].size();j++){
                ans += ac[i][j];
            }
            mx= max(ans, mx);
        }
        return mx;
    }
};
// @lc code=end


int main(){

    return 0;
}