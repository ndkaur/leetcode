/*
 * @lc app=leetcode id=1781 lang=cpp
 *
 * [1781] Sum of Beauty of All Substrings
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
    int beautySum(string s) {
        int n= s.size();
        int ans =0;
        for(int i=0; i<n; i++){
            vector<int> visited(26,0);
            for(int j=i; j<n; j++){
                visited[s[j] - 'a']++;
                ans = ans + beauty(visited);
            }
        }
        return ans;
    }
    int beauty(vector<int>& visited){
        int mf = -1;
        int lf = 1e9;
        for(int i=0; i<26; i++){
            mf = max(mf , visited[i]);
            if(visited[i] >= 1){
                lf = min(lf ,  visited[i]);
            }
        }
        return mf -lf;
    }
};
// @lc code=end



int main(){

    return 0;
}