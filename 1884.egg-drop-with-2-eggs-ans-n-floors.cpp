#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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

class Solution0 {
public:
    int twoEggDrop(int f) {
        int e=2;
        int ans =solve(e,f);
        return ans;
    }
    int solve(int egg , int floor){
        if(floor ==0 || floor ==1)
            return floor;
        if(egg == 1)
            return floor;
        int mn = INT_MAX;
        for(int k=1;k<=floor;k++){ 
            // break , not break
            int temp = 1+ max(solve(egg-1, k-1),solve(egg,floor-k));
            mn= min(mn,temp);
        }
        return mn;
    }
}; // time limit exceeded


class Solution1 {
    vector<vector<int>>dp;
public:
    int twoEggDrop(int f) {
        int e=2;
        dp=vector<vector<int>>(3,vector<int>(1001,-1));
        int ans =solve(e,f);
        return ans;
    }
    int solve(int egg , int floor){
        if(dp[egg][floor]!=-1)
            return dp[egg][floor];
        if(floor ==0 || floor ==1)
            return floor;
        if(egg == 1)
            return floor;
        int mn = INT_MAX;
        for(int k=1;k<=floor;k++){ 
            // break , not break
            int temp = 1+ max(solve(egg-1, k-1),solve(egg,floor-k));
            mn= min(mn,temp);
        }
        return dp[egg][floor]=mn;
    }
};

class Solution {
    vector<vector<int>>dp;
public:
    int twoEggDrop(int f) {
        int e=2;
        dp=vector<vector<int>>(3,vector<int>(1001,-1));
        int ans =solve(e,f);
        return ans;
    }
    int solve(int egg , int floor){
        if(dp[egg][floor]!=-1)
            return dp[egg][floor];
        if(floor ==0 || floor ==1)
            return floor;
        if(egg == 1)
            return floor;
        int mn = INT_MAX;
        for(int k=1;k<=floor;k++){ 
            // break , not break
            int low,high;
            if(dp[egg-1][k-1]!=-1)
                low= dp[egg-1][k-1];
            else {
                low= solve(egg-1,k-1);
                dp[egg-1][k-1] = low;
            }
            if(dp[egg][floor-k]!=-1)
                high=dp[egg][floor-k];
            else{
                high = solve(egg,floor-k);
                dp[egg][floor-k]=high;
            }
            int temp = 1+ max(low,high);
            mn= min(mn,temp);
        }
        return dp[egg][floor]=mn;
    }
};


int main(){
    Solution sol;
    int f=50;
    int ans = sol.twoEggDrop(f);
    cout<<ans;
    return 0;
}