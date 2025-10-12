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
    long long f(int i, vector<int>& pow, map<int,int>& mp, vector<long long int>& dp){
        int n = pow.size();
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];

        int val = pow[i]+3;
        int idx = lower_bound(pow.begin(), pow.end(), val)-pow.begin();
        long long int pick = pow[i] * 1LL * mp[pow[i]] + f(idx, pow, mp, dp);
        
        long long int npick = f(i+1, pow, mp, dp);
        return dp[i] = max(pick, npick);
        
    }
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        map<int,int> mp;
        vector<int> pow;

        for(int i=0; i<n; i++){
            mp[power[i]]++;
        }
        for(auto itr:mp){
            pow.push_back(itr.first);
        }

        sort(pow.begin(), pow.end());

        vector<long long int> dp(pow.size(), -1);
        return f(0,pow, mp,dp);
    }
};



int main(){

    return 0;
}