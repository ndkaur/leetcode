/*
 * @lc app=leetcode id=1760 lang=cpp
 *
 * [1760] Minimum Limit of Balls in a Bag
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
    int minimumSize(vector<int>& nums, int op) {
        int n= nums.size();
        int r= *max_element(nums.begin(),nums.end());
        int l=1;
        int ans;
        while(l<=r){
            int mid= l+(r-l)/2;
            int reqOperation = possible(nums,mid);
            if(reqOperation<= op){ // if less required operation .. reduce numbers to increase operations
                ans= mid;
                r= mid-1;
            } else{ 
                l=mid+1;
            }
        }
        return ans;
    }
    int possible(vector<int>&nums, int mid){
        int reqOperation=0;
        for(int num:nums){
            reqOperation+= num/mid; // to know how many parts of num can be possible
            if(num%mid==0)
                reqOperation--;
        }
        return reqOperation;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={9};
    int op= 2;
    int ans = sol.minimumSize(nums,op);
    cout<<ans;
    return 0;
}