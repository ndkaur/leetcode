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
    const int MOD = 1e9+7;
    int solve(int i, int g, vector<vector<int>>& mat, vector<vector<int>>& dp){
        int n = mat.size();
    
        if(i==n){
            if(g==1)
                return 1;
            else
                return 0;
        }

        if(dp[i][g]!=-1)
            return dp[i][g];

        long long ans =0;
        for(int j=0; j<mat[i].size(); j++){
            int val = mat[i][j];
            int new_gcd;
            if(i==0) // we at first row only 
                new_gcd = val;
            else 
                new_gcd = __gcd(g, val);

            ans = (ans+ solve(i+1, new_gcd, mat, dp))%MOD;
        }
        dp[i][g]= ans;
        return ans;
    }
    int countCoprime(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(151,-1));
        // i, prev_gcd, mat, dp
        return solve(0, 0, mat, dp);
    }
};


class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        const int MOD = 1e9+7;
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int,long long> mp;
        mp[0]=1;
        for(int i=0; i<n; i++){
            unordered_map<int, long long> next;
            for(auto [val, cnt]:mp){
                for(int num:mat[i]){
                    int new_val = (val==0? num : gcd(val, num));
                    next[new_val] = (next[new_val]+ cnt) %MOD;
                }
            }
            mp.swap(next);
        }
        return mp.count(1) ?  mp[1] :0;
    }
};


int main(){

    return 0;
}