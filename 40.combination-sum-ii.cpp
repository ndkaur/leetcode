/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> sol;
        vector<int> subpart={};
        help(candidates,target,subpart,sol,0);
        return sol;
    }
    void help(vector<int>& candidates, int target, vector<int>& subpart,vector<vector<int>>& sol,int begin){
        int n = candidates.size();
        if(target==0){
            sol.push_back(subpart);
            return ;
        } 
        else{
            for(int i=begin;i<n;i++){
                if(candidates[i]>target)  // if num greater than target
                    return ; 
                if(i && candidates[i]==candidates[i-1] && i>begin)
                    continue; // if dublicate combination exist 
                subpart.push_back(candidates[i]);
                help(candidates,target-candidates[i],subpart,sol,i+1);
                subpart.pop_back();
            }
        }
    }
};

// we cant directly use the same method as combination sum 1 cause in this the char are repeating 
// we can add our temp values in a set , then take those val out of set 
// so all this will take  O( 2^n * k * log n)

class Solution { //O(2^n * k)  // k*x   k= length x= combnations 
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(0, target, cand, temp, ans);
        return ans;
    }
    void f(int idx, int target, vector<int>& cand, vector<int>& temp, vector<vector<int>>& ans){
        int n= cand.size();
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        // for that idx we can pick the remanining values so use for loop
        for(int i=idx; i<n; i++){
            // we dont pick the duplicates to avoid the repeatitive combinations 
            if(i > idx && cand[i] == cand[i-1]) //not pick
                continue; // move to the next iteration
            // base condition  
            if(cand[i] > target) 
                break; // move out of the loop 
            // pick  
            temp.push_back(cand[i]);
            f(i+1, target- cand[i], cand, temp, ans);
            temp.pop_back();
        }
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> candidates={10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans=sol.combinationSum2(candidates,target);
    for(auto x:ans)
        print(x);
    return 0;
}