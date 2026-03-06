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
    int f(int n, vector<int>& dp){
        if(n==1)
            return 0;

        if(dp[n]!=-1)
            return dp[n];
        int ans = INT_MAX;
        for(int val1=1; val1<n; val1++){
            int val2 = n-val1;
            ans = min(ans, (val1*val2) + f(val1, dp) + f(val2, dp));
        }
        // int val1=0, val2=0;
        // if(n%2==0){
        //     val1= n/2;
        //     val2 = n/2;
        // }
        // else{
        //     val1 = n/2;
        //     val2 = val1+1;
        // }
        // ans = min(ans, (val1*val2) + f(val1, dp) + f(val2, dp));
        return dp[n] = ans;
    }
    int minCost(int n) {
        vector<int> dp(n+1,-1);
       
        return f(n,dp);
    }
};


class Solution {
public:
    int minCost(int n) {
        return (n * (n - 1)) / 2;
    }
};

int main(){

    return 0;
}