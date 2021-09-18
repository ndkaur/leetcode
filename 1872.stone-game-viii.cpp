/*
 * @lc app=leetcode id=1872 lang=cpp
 *
 * [1872] Stone Game VIII
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}
// @lc code=start
class Solution {
public:
    int stoneGameVIII(vector<int>& s) {
        int n= s.size();
        for(int i=1;i<n;i++)
            s[i] += s[i-1]; // prefix sum 
        int ans= s.back();
        for(int i=n-2;i>0;i--){
            ans = max(ans,s[i]-ans);
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> s= {7,-6,5,10,5,-2,-6};
    int ans = sol.stoneGameVIII(s);
    cout<<ans;
   return 0;
}