/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums[n-1]!=n)
            return n;
        else if (nums[0]!=0)
            return 0;
        for(int i=1;i<=n;i++){
            int expect = nums[i-1]+1;
            if(nums[i]!=expect)
                return expect;
        }
        return -1;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        vector<int> arr(n+1,0);
        for(int i=0; i<n; i++){
            arr[nums[i]] = 1;
        }
        int ans =0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==0)
                ans= i;
        }
        return  ans;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int total = n* (n+1) /2;
        int sum =0;
        for(auto num:nums)
            sum+= num;
        return total - sum;
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        for(int num:nums){
            n = n ^ num;
            n = n ^ i;
            i++;
        }
        return n;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={9,6,4,2,3,5,7,0,1};
    int ans=sol.missingNumber(nums);
    cout<<ans;
    return 0;
}