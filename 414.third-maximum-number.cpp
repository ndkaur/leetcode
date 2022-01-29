/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
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
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        for(auto x:nums){
            s.insert(x);
            if(s.size()>3)
                s.erase(s.begin());
        }
        if(s.size()==3)
           return *s.begin();
        else
            return *s.rbegin();
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        if(n<3){
            return nums[n-1];
        }
        int count=0;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                count++;
            }
            if(count==2){
                return nums[i-1];
            }
        }
        return nums[n-1];
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> arr={2,1};
    int out=sol.thirdMax(arr);
    cout<<out;
    return 0;
}