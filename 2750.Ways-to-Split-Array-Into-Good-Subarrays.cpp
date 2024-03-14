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
    int mod = 1e9+7;
    int f(int idx, int cnt, vector<int>& nums, vector<vector<int>>& dp){
        if(idx<0){
            if(cnt==1)
                return 1;
            return 0;
        }
        if(nums[idx]==1)
            cnt++;
        // we can only have 1 one
        if(cnt>1)
            return 0;

        if(dp[idx][cnt]!=-1)
            return dp[idx][cnt];
        
        // pick means we adding to the same subaraay , no split happended till now 
        int pick = f(idx-1, cnt, nums, dp);

        // not pick means we now starting a new subaaray and the split has happended at the curr idx
        int npick = 0;
        if(cnt==1){ // we can only split when subarray has 1 one 
            npick = f(idx-1, 0, nums, dp);
        }

        return dp[idx][cnt] = (pick + npick)%mod;
    }
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        // idx , cnt of ones occuring till that idx 
        return f(n-1, 0, nums, dp);
    }
};


class Solution {
public:
    int mod = 1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1;
        int cnt = 0;
        int i=0;
        // removing the starting zeroes
        while(i<n && nums[i]==0){
            i++;
        }
        // after this while loop i will be standing at the first one 
        if(i>=n)
            return 0;
        
        // ans = cnt of zeroes between two 1's 
        // ans = ans * cnt+1  -> cnt+1 as we can have n+1 divisions possible in between n zeroes 
        while(i<n){
            // now iterating till next 1 is not found 
            // keep track of count of zeroes in between using cnt 
            if(nums[i]==1){
                ans = (ans * (cnt+1))%mod;
                cnt = 0;
            }
            else 
                cnt++;
            i++;
        }
        return ans;
    }
};

int main(){

    return 0;
}