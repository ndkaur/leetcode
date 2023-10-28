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
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        int len = f(0, 0, nums, target, dp, len);
        if(len<0)
            return -1;
        return len;
    }
    int f(int idx, int temp, vector<int>& nums, int& target, vector<vector<int>>& dp, int& len){
        int n = nums.size();
        if(idx == n){
            if(temp==target){
                len = max(len, 0);
                return 0;
            }
            return INT_MIN;
        }
        if(dp[idx][temp]!=-1)
            return dp[idx][temp];
        int take =INT_MIN;
        if(nums[idx]+temp <= target){
            take = 1+f(idx+1, temp+nums[idx], nums, target, dp, len);
        }
        int nottake = f(idx+1, temp, nums, target, dp, len);
        return dp[idx][temp] = max(take, nottake);
    }
};

int main(){

    return 0;
}