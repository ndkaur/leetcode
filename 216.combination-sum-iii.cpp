/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subgroup;
        help(ans, subgroup,k,n);
        return ans;
    }
    void help(vector<vector<int>>& ans, vector<int>& subgroup, int k,int n){
        if(subgroup.size()==k && n==0){
            ans.push_back(subgroup);
            return;
        }
        if(subgroup.size()<k){
            // we have to move through the number counting 
            // if 1 is the 1 then next i must be 2
            for(int i= subgroup.empty()?1:subgroup.back()+1;i<=9;i++){
                if(n-i < 0) break; // total- curr is -ve then break
                subgroup.push_back(i);
                help(ans, subgroup, k, n-i);
                subgroup.pop_back();
            }
        }
    }
};


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        find(1, k, n, temp, ans);
        return ans;
        
    }
    void find(int idx, int sz, int sum, vector<int>& temp, vector<vector<int>>& ans){
        if(sum < 0 || temp.size() > sz)
            return;
        if(sum == 0 && temp.size() == sz){
            ans.push_back(temp);
            return;
        }
        for(int i=idx; i<=9; i++){
            temp.push_back(i);
            find(i+1, sz, sum-i, temp, ans);
            temp.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        find(1, k, n, temp, ans);
        return ans;
        
    }
    void find(int idx, int sz, int sum, vector<int>& temp, vector<vector<int>>& ans){
    
        if(temp.size() == sz){
            if(sum == 0){
                ans.push_back(temp);
            }
            return;
        }
        // dont want to pick duplicates 
        for(int i=idx; i<=9; i++){
            if(i<=sum){
                temp.push_back(i);
                find(i+1, sz, sum-i, temp, ans);
                 temp.pop_back();
            }
        }
    }
};
// @lc code=end


int main(){
    Solution sol;
    int k =3;
    int n=9;
    vector<vector<int>> ans=sol.combinationSum3(k,n);
    for(auto x:ans)
        print(x);
    return 0;
}