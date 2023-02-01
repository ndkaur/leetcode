/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
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
    string gcdOfStrings(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // leetcode != codeleet
        // abcabcabc == abcabcabc
        // gcd(6,3) = 3
        if(s1+s2 == s2+s1){
            return s1.substr(0, gcd(n,m));
        }
        return "";
    }
};
// @lc code=end


int main(){

    return 0;
}