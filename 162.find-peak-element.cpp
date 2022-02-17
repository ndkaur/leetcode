/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
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
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        int l= 0;
        int h= n-1;
        while(l<h){
            int mid= l+(h-l)/2;
            if(nums[mid]>nums[mid+1])
                h= mid;
            else 
                l=mid+1;
        }
        return l;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2,1,3,5,6,4};
    int ans = sol.findPeakElement(nums);
    cout<<ans;
    return 0;
}