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

class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        map<string,int> mp;
        for(auto d:dict){
            mp[d]++;
        }
        vector<int> dp(n,-1);
        return f(0,s, mp, dp);
    }
    int f(int idx, string& s, map<string,int>& mp, vector<int>& dp){
        int n = s.size();
        if(idx>=n)
            return 0;

        if(dp[idx]!=-1)
            return dp[idx];

        int ans = n;  // the full len array 
        string temp ="";
        for(int i=idx; i<n; i++){
            temp.push_back(s[i]);
            int extra  = temp.size();
            if(mp.find(temp)!=mp.end())
                extra = 0;
            // find extra required from next iteration
            extra = extra + f(i+1, s, mp, dp);
            ans = min(ans, extra);
        }
        return dp[idx] = ans;
    }
};

int main(){

    return 0;
}

// leetscode 
// recursion will be like 
// 0 1 2 3 4 5 6 7 8 
// l e e t s c o d e

// f(0)
//  l+ f(1) , le+f(2), lee + f(3), leet+ f(4), leets + f(5) , leetsc+ f(6), leetsco + f(7), leetscod + f(8) , leetscode+ f(9)
//   e+ f(2) , ee + f(3), eet+f(4), eets+f(5), eetsc+f(6) ...... 
//   e+f(3)
//   t+f(4)
//   s + f(5)
//   c +f(6)
//   o + f(7)
//  d + f(8)
//  f(9) = 0

//  the calls that give us ans are 
//  ans = size = 13 
//  f(0) -> leet + f(4) -> s + f(5) ->  code + f(9) 
//  f(9) = 0 
// f(0) -> leet + f(4) -> s + f(5) -> code + 0
// f(0) -> leet + f(4) -> s + f(5) ->  0 + 0 
//  f(0) -> leet + f(4) -> 1 + 0 min(ans, extra)
// f(0) -> leet + 1 
// f(0) -> 0+1 
//  f(0) = 1 

