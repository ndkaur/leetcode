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

class Solution0 {
public:
    bool validPartition(vector<int>& nums) {
        int n= nums.size();
        return f(0,nums);
    }
    bool f(int i, vector<int>& nums){
        int n= nums.size();
        // base case
        if(i==n) return true;
        // when two elemts are equal
        if(i+1<n && nums[i]==nums[i+1]){
            // moving to next index
            if(f(i+2,nums))
                return true;
            // when 3 ele are equal
            if(i+2<n && nums[i]==nums[i+2]){
                if(f(i+3,nums))
                    return true;
            }
        }
        // when in increasing order 
        if(i+2<n && nums[i]+1== nums[i+1] && nums[i+1]+1== nums[i+2])
            if(f(i+3,nums))
                return true;
        return false;
    }
};


class Solution { // O(N) dp 
public:
    bool validPartition(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp);
    }
    bool f(int i, vector<int>& nums,vector<int>& dp){
        int n= nums.size();
        // base case
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        // when two elemts are equal
        if(i+1<n && nums[i]==nums[i+1]){
            if(f(i+2,nums,dp))
                return dp[i]=true;
            // when 3 ele are equal
            if(i+2<n && nums[i]==nums[i+2]){
                if(f(i+3,nums,dp))
                    return dp[i]=true;
            }
        }
        // when in increasing order 
        if(i+2<n && nums[i]+1== nums[i+1] && nums[i+1]+1== nums[i+2])
            if(f(i+3,nums,dp))
                return dp[i]=true;
        return dp[i]=false;
    }
};

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;

        if(nums[1]==nums[0])
            dp[2] =1;
        for(int i=2; i<n; i++){
            if(nums[i]==nums[i-1])// 2 equal // i=2 but dp->i =3
                dp[i+1] = dp[i+1] || dp[i-1];
            // 3 equal
            if(nums[i]==nums[i-1] && nums[i]==nums[i-2])
                dp[i+1] = dp[i+1] || dp[i-2];
            // inc 
            if(nums[i]==nums[i-1]+1 && nums[i]==nums[i-2]+2)
                dp[i+1] = dp[i+1] || dp[i-2];
        }
        return dp[n];
    }
};

int main(){

    return 0;
}