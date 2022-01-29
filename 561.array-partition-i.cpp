/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition I
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // print(nums);
        int sum=0;
        for(int i=0;i<n;i=i+2){
            if(nums[i]>nums[i+1])// for finding minimun
            {
                sum=sum+nums[i+1];
            }
            else
            {
              sum=sum+nums[i];
            }
        }
            return sum;
    }
};

class Solution0 {
public:
    int arrayPairSum(vector<int>& nums) {
        int n= nums.size();
        int ans =0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=2){
            ans += min(nums[i],nums[i+1]);
        }
        return ans;
    }
};

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n= nums.size();
        int ans =0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            //1 2 3 4
            ans += nums[i];
            i++;
        }
        return ans;
    }
};

int main(){
   Solution sol;
   vi nums={1,4,3,2};
   int sum=sol.arrayPairSum(nums);
   cout<<sum;


    return 0;
}

// @lc code=end
