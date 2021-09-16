/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
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
    string reverseOnlyLetters(string s) {
        int n = s.size();
        for(int i=0,j=n-1;i<j;){
            if(!isalphaa(s[i]))
                i++;
            else if(!isalphaa(s[j]))
                j--;
            else 
                swap(s[i++],s[j--]);
        }
        return s;
    }
    bool isalphaa(int c){
        if((c>='a' && c<='z') || (c>='A' && c<='Z'))
            return 1;
        else 
            return 0;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s="a-bC-dEf-ghIj";
    string ans = sol.reverseOnlyLetters(s);
    for(auto c:ans)
        cout<<c;
   return 0;
}