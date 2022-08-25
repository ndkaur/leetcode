/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
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

// brute force using set 
// Time Complexity: O( 2^n *(k log (x) ))
// Space Complexity:  O(2^n * k) 

class Solution {
  public:
    void fun(vector < int > & nums, int index, vector < int > temp, set < vector < int >> & res) {
      if (index == nums.size()) {
        sort(temp.begin(), temp.end());
        res.insert(temp);
        return;
      }
      temp.push_back(nums[index]);
      fun(nums, index + 1, temp, res); // pick 
      temp.pop_back();
      fun(nums, index + 1,temp, res); // not pick 
    }
  vector < vector < int >> subsetsWithDup(vector < int > & nums) {
    vector < vector < int >> ans;
    set < vector < int >> res;
    vector < int > temp;
    fun(nums, 0, temp, res);
    for (auto it = res.begin(); it != res.end(); it++) {
      ans.push_back( * it);
    }
    return ans;
  }
};


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(0, nums, temp, ans);
        return ans;
    }
    void f(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        int n= nums.size();
        ans.push_back(temp);
         
        for(int i=idx; i<n; i++){
            if(i>idx && nums[i]== nums[i-1])
                continue;
            temp.push_back(nums[i]);
            f(i+1, nums, temp, ans);
            temp.pop_back();
        }
    }
};
// @lc code=end


int main(){

    return 0;
}