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

// solve using segment tree 

// tle 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> dp(n,1);
        for(int i=0; i<n ; i++){
            for(int prev=0; prev<i; prev++){
    
                if(nums[prev] < nums[i] && nums[i]-nums[prev]<=k){
                    dp[i] = max(dp[i], 1+dp[prev]);
                }
            }
        }
        int ans =-1;
        for(int i=0; i<n; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


int main(){

    return 0;
}