/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
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
    string toLowerCase(string &str) {
        int n=str.size();
        for(char &c:str){
            if('A'<=c && c<='Z'){
                c ='a'+(c-'A');
            }
        }
        return str;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string str="Hello";
    string ans=sol.toLowerCase(str);
    for(auto c:ans){
        cout<<c;
    }
    return 0;
}