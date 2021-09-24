/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
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
    string breakPalindrome(string p) {
        int n= p.size();
        if(n==1) return "";
        for(int i=0;i<n/2;i++){
            if(p[i]!='a'){
                p[i] ='a';
                return p;
            }
        }
        p[n-1]='b';
        return p;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string p="abccba";
    string ans = sol.breakPalindrome(p);
    for(auto c:ans)
        cout<<c;
    return 0;
}