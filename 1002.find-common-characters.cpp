/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string> output;
        vector<map<char,int>> counts;
        for(auto word: words){
            map<char,int> m;
            for(auto c: word){
                m[c]++;
            }
            counts.push_back(m);
        }
        // mc=min count
        for(auto c='a'; c<='z'; ++c){
            int mc = 1000;
            for(auto count: counts){
                mc = min(mc, count[c]);
            }
            for(int t=0; t<mc; ++t){
                output.push_back(string(1,c));
            }
        }
        return output;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<string> A={"bella","label","roller"};
    vector<string> output=sol.commonChars(A);
    for(auto s: output){
        cout<<s<<" ";
    }
    return 0;
}