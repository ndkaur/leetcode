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


// backtracking 
//  time-> O( n! * n)
// space -> O(n) + O(n) (extra space due to freq array )
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> freq(n,0);
        f(temp, freq, ans, nums);
        return ans;
    }
    void f(vector<int>& temp, vector<int>& freq, vector<vector<int>>& ans, vector<int>& nums){
        int n = nums.size();
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        // genetare all permutations for unvisited nums
        for(int i=0; i<n; i++){
            if(!freq[i]){ 
                temp.push_back(nums[i]);
                freq[i]=1; // visited
                f(temp, freq, ans, nums); // pick
                // backtrack
                freq[i]=0;
                temp.pop_back();
            }
        }
    }
};

//  time-> O( n! * n)
// space -> O(n) 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        f(0, ans, nums);
        return ans;
    }
    void f(int idx, vector<vector<int>>& ans, vector<int>& nums){
        int n= nums.size();
        if(idx== n){
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<n;i++){
            swap(nums[idx], nums[i]);
            // pick move ahead 
            f(idx+1, ans, nums);
            // backtarck 
            swap(nums[idx], nums[i]);
        }
    }
};

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
