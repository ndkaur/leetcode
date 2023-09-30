/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
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
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;

        int num = INT_MIN;
        for(int i=n-1; i>=0; i--){
            if(nums[i]<num){
                return true;
            }
            // monotonic decreasing stack 
            // termination condition will be inc order 
            while(!stk.empty() && stk.top()<nums[i]){
                num = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};


// @lc code=end


int main(){

    return 0;
}