/*
 * @lc app=leetcode id=1309 lang=cpp
 *
 * [1309] Decrypt String from Alphabet to Integer Mapping
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
    string freqAlphabets(string s) {
        int n=s.length();
        string result="";
        for(int i=0;i<n;){
            if(i+2<n && s[i+2]=='#'){
                int num = (s[i]-'0')*10 + (s[i+1]-'0');
                result+= char('a'+num-1);
                i=i+3;
            }
            else{
               result +=char('a'+s[i]-'0'-1);
               i++;
            }
        }
        return result;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s="1326#";
    string ans=sol.freqAlphabets(s);
    for(auto c:ans){
        cout<<c;
    }
    return 0;
}