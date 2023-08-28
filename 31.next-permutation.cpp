/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
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

// @lc code=start

class Solution0 { //O(N)  O(1)
public:
    void nextPermutation(vector<int>& nums) {
        // {1,2,3} -> {1,3,2} ->2<3 
        // {3,2,1} -> reverse = {1,2,3}
        int n  = nums.size();
        int idx = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break; 
            }
        }
        // now swap 
        for(int i=n-1; i>=idx && idx!=-1; i--){
            if(nums[i]> nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }
        // in some cases swap might not work so reverse
        // but we will reverse that part which is not countered in swap
        reverse(nums.begin()+idx+1, nums.end());

    }
};


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // {1,2,3} -> {1,3,2} ->2<3 
        // {3,2,1} -> reverse = {1,2,3}
        next_permutation(nums.begin(), nums.end());
    }
};





// @lc code=end


int main(){

    return 0;
}