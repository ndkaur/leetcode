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


//  recursion  backtracking 
// time- >O( 2^t) *k   t=no of times a elem is picked  , k= len of the temp array formed 
// space ->O(n)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(0, cand, target, temp, ans);
        return ans;
    }
    void f(int idx, vector<int>& cand, int target, vector<int>& temp, vector<vector<int>>& ans){
        int n= cand.size();
        if(idx==n){
            if(target==0)
                ans.push_back(temp);
            return;
        }
        // pick the elem
        if(cand[idx] <= target){
            temp.push_back(cand[idx]);
            f(idx, cand, target - cand[idx], temp, ans);
            // if the num did gave us the target so before backtraking and going to previous state remove it also 
            temp.pop_back();
        }
        // not pick the elem
        f(idx+1, cand, target, temp ,ans); 
    }
};

// 0 1 2 3
// // 2 3 6 7
//                                   f(0,7) -{}
//                 {2}      f(0,5)              f(1,7)
//             {2,2}     f(0,3)   f(1,5)     f(1,)

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