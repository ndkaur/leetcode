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