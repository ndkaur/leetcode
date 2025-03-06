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


class Solution { // O(n^2) , O(n^2)
    public:
        int f(int prev, int curr, vector<int>& nums, vector<vector<int>>& dp){
            int n = nums.size();
            // single elem left , if odd length array 
            if(curr==n) // curr is out of bound return prev elem
                return nums[prev];
            // 2 elem left , if even length array 
            if(curr==n-1){
                return max(nums[curr], nums[prev]);
            }
    
            if(dp[prev][curr]!=-1)
                return dp[prev][curr];
            
            // trying all 3 cases taking each elem from the 3 elemts for max
            // a, b, c  -> first = max(b,c)
            // a, b, c -> second = max(a, c)
            // a, b, c -> third = max(a, b)
            // taken number is removed form the array 
            int first = max(nums[curr], nums[curr+1]) + f(prev, curr+2, nums, dp);
            int second = max(nums[prev], nums[curr+1]) + f(curr, curr+2, nums, dp);
            // max(a,b) -> prev moves to third pos and curr move to foruth 
            int third = max(nums[prev], nums[curr]) + f(curr+1, curr+2, nums, dp);
    
            return dp[prev][curr] = min({first, second, third});
        }
        int minCost(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
            // prev idx, cur idx
            return f(0, 1, nums, dp);
        }
};


int main(){

    return 0;
}