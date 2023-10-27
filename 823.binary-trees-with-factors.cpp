/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
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
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        long ans = 0;
        long mod = 1e9+7;
        sort(arr.begin(), arr.end());
        // used map cause we eant to find what is present at the exact location required
        unordered_map<int,long> dp;
        for(int i=0; i<n; i++){
            dp[arr[i]] = 1;
            for(int j=0; j<i; j++){
                if(arr[i]%arr[j]==0){
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i]/arr[j]])%mod;
                }
            }
            ans = (ans + dp[arr[i]]) % mod;
        }
        return ans;
    }
};

class Solution0 {
    int mod = 1e9 +7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n= arr.size();
        sort(arr.begin(),arr.end());
        unordered_set<int> s;
        s.insert(arr.begin(),arr.end());

        int ans = 0;
        for(auto &cur:arr){
            ans += cnt(cur,s);
        }
        return ans;
    }
    int cnt(int root,unordered_set<int>& s){
        int count=1;
        for(auto &val:s){
            if(root % val != 0)
                continue;
            int fac1= val; //10
            int fac2= root/val; // 10/2 =5
            if(s.count(fac2)){ //5 present
                count += cnt(fac1,s) * cnt(fac2,s);
                count %= mod;
            }
        }
        return count;
    }
};


class Solution {
    int mod = 1e9 +7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n= arr.size();
        sort(arr.begin(),arr.end());
        unordered_set<int> s;
        s.insert(arr.begin(),arr.end());

        unordered_map<int,long long int> dp;
    
        int ans = 0;
        for(auto &cur:arr){
            ans += cnt(cur,s,dp);
            ans %= mod;
        }
        return ans;
    }
    long long int cnt(int root,unordered_set<int>& s, unordered_map<int,long long int>& dp){
        if(dp.count(root))
            return dp[root];
        
        long long int count=1;

        for(auto &val:s){
            if(root % val != 0)
                continue;
            int fac1= val; //10
            int fac2= root/val; // 10/2 =5
            if(s.count(fac2)){ //5 present
                count += cnt(fac1,s,dp) * cnt(fac2,s,dp);
                count %= mod;
            }
        }
        return dp[root]=count;
    }
};


// @lc code=end


int main(){

    return 0;
}