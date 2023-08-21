/*
 * @lc app=leetcode id=2009 lang=cpp
 *
 * [2009] Minimum Number of Operations to Make Array Continuous
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
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        // first condition must be unique
        set<int> s;
        for(auto num:nums)
            s.insert(num);
        vector<int> arr;
        for(auto itr:s){
            arr.push_back(itr);
        }
        int ans = INT_MAX;
        // unique array formed 
        // second condition -> mx - min = n-1
        for(int i=0; i<arr.size(); i++){
            int first = arr[i];
            // conditon = last - first = n-1
            // l = n-1 + first
            int last = first + n-1;
            // now we need to fing ub for last to replace and to fulfill condition 2
            int ub = upper_bound(arr.begin(), arr.end(), last) - arr.begin();
            // the curr len fulfilling both conditons
            // curr len = total len - (r-l)
            ans = min(ans, n-(ub-i));
        } 
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}