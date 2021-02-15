/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}


// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n= s.size();
        vector<int> ans(n,n);
        int pos= -n;
        for(int i=0;i<n;i++){ // pos(already set as -12),i so i-pos 
            if(s[i]==c)
                pos=i;
            ans[i]=i-pos; // when i not same ans[i] is -12
        }
        for(int i=pos-1;i>=0;i--){ // i pos so pos-i 
            if(s[i]==c)
                pos=i;
            ans[i]= min(ans[i],pos-i);
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s = "loveleetcode";
    char c = 'e';
    vector<int>ans ;
    ans= sol.shortestToChar(s,c);
    print(ans);
    return 0;
}