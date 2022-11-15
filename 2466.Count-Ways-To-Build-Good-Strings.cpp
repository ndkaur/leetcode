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

// TC : O(high) SC :- O(high)   
class Solution {
public:
    int mod = 1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        int ans =0;
        for(int i=low; i<=high; i++){
            ans = ((ans %mod) + (find(i,zero, one, dp)%mod)) % mod;
        }
        return ans;
    }
    int find(int target, int zero, int one, vector<int>& dp){
        if(target == 0)
            return 1;
        if(target<0)
            return 0;
        if(dp[target] != -1)
            return dp[target];
        long long sum;
        // sum = pick zero  + pick one 
        // len - number of zeros 
        sum = find(target-zero , zero, one, dp) + find(target-one, zero, one, dp);
        return dp[target] = (sum) %  mod;
    }
};


// TC : O(high) SC :- O(high)

class Solution {
public:
    int mod = 1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,0);
        dp[0] = 1;
        int ans =0;

        for(int i=1; i<=high; i++){
            // can add zero remaining
            if(i>=zero)
                dp[i] = (dp[i] + dp[i-zero] ) % mod;
            // one count still remaining then can add one to string 
            if(i>=one)
                dp[i] = (dp[i] + dp[i-one]) % mod;
            // if len exist between the low and high the add to ans
            if(i>=low)
                ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};

int main(){

    return 0;
}