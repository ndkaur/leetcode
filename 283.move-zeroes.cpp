/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
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
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        vector<int> arr;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(nums[i]!=0)
                arr.push_back(nums[i]);
            else 
                cnt++;
        }
        while(cnt--){
            arr.push_back(0);
        }
        nums = arr;
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nzero=0;
        for(int curr=0;curr<nums.size();curr++){
            if(nums[curr]!=0){
                swap(nums[nzero],nums[curr]);
                nzero++;
            }
        }
        
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,0,8,0,3,5,7,0};
    sol.moveZeroes(nums);
    print(nums);
    return 0;
}