/*
 * @lc app=leetcode id=1370 lang=cpp
 *
 * [1370] Increasing Decreasing String
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
    string sortString(string s) {
        int n= s.size();
        map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        string ans="";
        int len=0;
        while(len!=n){
            for(char x='a';x<='z';x++){
                if(mp[x]){
                    ans+= x;
                    mp[x]--;
                    len++;
                }
            }
            for(char x='z';x>='a';x--){
                if(mp[x]){
                    ans+= x;
                    mp[x]--;
                    len++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}