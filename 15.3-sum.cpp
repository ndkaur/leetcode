/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>>  out;
        for(int i=0;i<n;i++){
            if(i && nums[i]==nums[i-1])// if duplicates of i exist
                continue; 

            int left=i+1;
            int right=n-1;

            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum>0) // if sum is greater .by right-- the positive value of r will decrease and summ will decrease
                    right--;

                else if(sum<0)// if sum is less, by l++ the value of sum will increase  
                    left++;
                
                else{ 
                    out.push_back({nums[i],nums[left],nums[right]});
                    
                    //duplicates of left and right
                    while(left+1<n && nums[left]==nums[left+1]) left++;
                    while(right-1>=0 && nums[right]==nums[right-1]) right--;
                    
                    left++;right--;
                }
            }
        }
        return out;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            // fix x , find y and z
            //x+ y+ z = 0 , y+z = 0-x = target
            int target= 0-nums[i]; //0-x
            int ptr1= i+1;
            int ptr2= n-1;
            
            while(ptr1<ptr2){
                int sum = nums[ptr1]+nums[ptr2];
                if(sum == target){
                    vector<int> temp = {nums[i],nums[ptr1],nums[ptr2]};
                    ans.push_back(temp);
                    // duplicates of ptr1
                    while(ptr1< ptr2 && nums[ptr1] == temp[1])
                        ptr1++;
                    // duplicated of ptr2
                    while(ptr1<ptr2 && nums[ptr1] == temp[2])
                        ptr2--;
                }
                else if(sum > target){
                    ptr2--;
                }
                else 
                    ptr1++;
            }
            // duplicated of 
            while(i+1< n && nums[i+1] == nums[i])
                i++;
        }
        return ans;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={-2,0,1,1,2};
    vector<vector<int>> out;
    out=sol.threeSum(nums);
    for(auto x:out){
        print(x);
    }
    return 0;
}