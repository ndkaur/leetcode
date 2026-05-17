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
    int f(int i, vector<int>& nums, int target, vector<int>& dp){
        if(i==0)
            return dp[i]=0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans =INT_MIN;
        for(int j=0; j<i; j++){
            if(abs(nums[j]-nums[i])<=target){
                ans = max(ans, 1+f(j, nums, target, dp));
            }
        }
        return dp[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = f(n-1, nums, target, dp);
        return ans<0 ? -1 :ans;
    }
};

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // jump total from j to ith indx 
        vector<int> dp(n,-1);
        dp[0] = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(abs(nums[i]-nums[j])<=target && dp[j]!=-1){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};

int main(){

    return 0;
}