/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
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
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk; // monotonic decreasing 
        vector<int> ans(n,-1);

        for(int i=0; i<n*2; i++){
            while(!stk.empty() && nums[stk.top()] < nums[i% n]){
                ans[stk.top()] = nums[i % n];
                stk.pop(); 
            }
            stk.push(i % n);
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}