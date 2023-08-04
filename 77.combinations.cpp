/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
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

// time ->O(n^k)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(1,n, k, temp, ans);
        return ans;
    }
    void f(int idx, int n , int k, vector<int>& temp, vector<vector<int>>& ans){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(idx == n+1)
            return;
            
        temp.push_back(idx);
        f(idx+1,n, k-1, temp, ans);
        temp.pop_back();

        f(idx+1, n, k, temp, ans);
    }
};


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(1,n, k, temp, ans);
        return ans;
    }
    void f(int idx, int& n , int k, vector<int>& temp, vector<vector<int>>& ans){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx; i<=n; i++){
            temp.push_back(i);
            f(i+1,n, k-1, temp, ans);
            temp.pop_back();
        }
    }
};


// @lc code=end



int main(){

    return 0;
}