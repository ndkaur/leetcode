/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
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
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        sort(can.begin(),can.end());
        vector<int> subpart={};
        vector<vector<int>> sol;
        help(can,target,subpart,sol,0);
        return sol;
    }

    void help(vector<int> &can,int target,vector<int>&subpart, vector<vector<int>> &sol,int begin) {
        if(target==0) sol.push_back(subpart);

        for(int i=begin;i<can.size();i++){
            int selected =can[i];
            
            if(selected<=target){
                subpart.push_back(selected);
                help(can,target-selected,subpart,sol,i);
                subpart.pop_back();
            }
        }
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> can={2,3,6,7};
    int target=7;
    vector<vector<int>> ans=sol.combinationSum(can,target);
    for(auto x:ans){
        print(x);
    }
    return 0;
}