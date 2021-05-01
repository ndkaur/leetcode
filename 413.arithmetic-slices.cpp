/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */
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

// @lc code=start
class Solution0 { // runtime 
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size();
        if(n<3) return 0;
        int count=0 ,result=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]-nums[i-1] == nums[i+1]-nums[i]){
                count++;
                result += count;
            }
            else 
                count=0;
        }
        return result;
    }
};

class Solution1 { // o(n^2)
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size();
        int count=0;
        for(int i=0;i<n-2;i++){
            int d = nums[i+1]-nums[i];
            for(int j=i+2;j<n;j++){
                if(nums[j]-nums[j-1]== d)
                    count++;
                else 
                    break;
            }
        }
        return count;
    }
};

// recursion 
class Solution2 { 
public:
    int sum=0;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size();
        slice(nums,n-1);
        return sum;
    }
    int slice(vector<int>& nums,int n){
        if(n<2) return 0;
        int count=0;
        if(nums[n]-nums[n-1] == nums[n-1]-nums[n-2]){
            count= 1+slice(nums, n-1);
            sum+= count;
        }
        else 
            slice(nums,n-1);
        return count;
    }
};


class Solution3 {  // dp
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n);
        int sum=0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i] = 1+ dp[i-1];
                sum+= dp[i]; 
            }
        }
        return sum;
    }
};

class Solution {  // constant space dp 
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size();
        int dp =0;
        int sum=0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp = 1+ dp;
                sum+= dp; 
            }
            else 
                dp=0;
        }
        return sum;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2,3,4};
    int ans= sol.numberOfArithmeticSlices(nums);
    cout<<ans;
    return 0;
}