/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
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
    string shiftingLetters(string s, vector<int>& shifts) {
        int n= shifts.size();
        int sum=0;
        for(int i=n-1;i>=0;i--){
            sum+= shifts[i];
            s[i] = (((s[i]-'a')+sum) % 26) + 'a';
        }
        return s;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> shifts= {1,2,3};
    string s ="aaa";
    string ans = sol.shiftingLetters(s,shifts);
    for(auto c:ans)
        cout<<c;
   return 0;
}