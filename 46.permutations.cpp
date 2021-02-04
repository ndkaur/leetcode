/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
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

// using reucrsive method 

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        int n= nums.size();
        pm(nums,0);
        return ans;
    }
    void pm(vector<int> &nums , int index){
        if(index==nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            pm(nums,index+1);
            swap(nums[i],nums[index]);
        }
        return;
    }
};
// o (n!)

//using stl 

class Solution1 {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
    return ans;
    }
};
// o(n!)
// @lc code=end

int main(){
    Solution1 sol;
    vector<int> nums={1,2,3};
    vector<vector<int>> ans= sol.permute(nums);
    for(auto x:ans){
        print(x);
    }
    return 0;
}
