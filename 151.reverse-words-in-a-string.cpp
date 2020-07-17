/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
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

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string result;
        int i=0;
        while(i<n){
            while(i<n && s[i]==' ')
                i++;
            if(i>=n)
                break;
            int j=i+1;
            while(j<n && s[j]!=' ')
                j++;
            string sub=s.substr(i,j-i);
        
            if(result.length()==0)
                result=sub;
            else 
                result=sub+" "+result;
            i=j+1;
        }
        return result;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string input="the sky is blue";
    string out;
    out=sol.reverseWords(input);
    cout<<out;
    return 0;
}