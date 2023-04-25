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
    int mod = 1e9+7;
    int numberOfArrays(string s, int k) {
        int ans = solve(s,k,0);
        return ans;
    }
    int solve(string& s, int& k, int idx){
        if(idx == s.size())
            return 1;
        long long currNum =0;
        long long ways =0;

        for(int i=idx; i<s.size(); i++){
            int currDig = s[i]-'0';
            currNum = (currNum*10) + currDig; 
            if(currNum < 1 || currNum >k)
                break;
            int nxtWays = solve(s,k,i+1);
            ways = (ways + nxtWays) % mod;
        }
        return (int)ways;
    }
};


class Solution {
public:
    int mod = 1e9+7;
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(),-1);
        int ans = solve(s,k,dp,0);
        return ans;
    }
    int solve(string& s, int& k,vector<int>& dp, int idx){
        if(idx == s.size())
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];

        long long currNum =0;
        long long ways =0;

        for(int i=idx; i<s.size(); i++){
            int currDig = s[i]-'0';
            currNum = (currNum*10) + currDig; 
            if(currNum < 1 || currNum >k)
                break;
            int nxtWays = solve(s,k,dp,i+1);
            ways = (ways + nxtWays) % mod;
        }
        return dp[idx] = ways;
    }
};



int main(){

    return 0;
}