/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
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
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        int count=0;

        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                if(count==0){
                    //if the n-2 th is greater
                    if(i-2>=0 && nums[i-2]>nums[i]){
                        nums[i] = nums[i-1];
                    }else{
                        //if the n-2 is smaller or donot exist
                        nums[i-1] = nums[i];
                    }
                    ++count;
                }else return false;
            }
        }

        return (count<=1);
    }
};

//   4 2 3 
// 1 4 2 4
// 3 4 2 3

// @lc code=end

int main(){
    Solution sol;
    vector<int> nums={4,2,3};
    bool out =sol.checkPossibility(nums);
    cout<<out<<endl;
    return 0;
}