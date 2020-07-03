/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
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

// USING FOR LOOP:-

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        while(true){
            n = s.size();
            bool rem = 0;
            for(int i=0; i<n-1; ++i){
                if(s[i]==s[i+1]){
                    s.erase(s.begin()+i); //used s.begin() because c is at that postion of equality
                    s.erase(s.begin()+i); // used i not i+1 because when we remove first i the string get shifted.
                    rem = true;
                    break;
                }
            }
            if(!rem) break;
        }
        return s;
     }
};

// USING STACK:-

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string ans;
        for(auto &c:s){
            if(ans.size() && ans.back()==c)
                ans.pop_back();
            else
                ans.push_back(c);
        }
        return ans;
    }
};



int main(){
    Solution sol;
    string S="abbaca";
    string ans=sol.removeDuplicates(S);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

// @lc code=end