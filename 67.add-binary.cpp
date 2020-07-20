/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
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
    string addBinary(string a, string b) {
        string result;
        int i= a.length()-1;
        int j=b.length()-1;
        int carry=0;
        while(i>=0 || j>=0){
             int sum=carry;
             if(i>=0){
                 sum=sum+a[i--]-'0';
             }
             if(j>=0){
                 sum=sum+b[j--]-'0';
             }
             carry=sum>1?1:0;
             result=result+ to_string(sum%2);
        }
        if(carry) 
            result=result+to_string(carry);
        reverse(result.begin(),result.end());
        return result;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string a="1010";
    string b="1011";
    string result=sol.addBinary(a,b);
    for(auto s:result){
        cout<<s;
    }
    return 0;
}