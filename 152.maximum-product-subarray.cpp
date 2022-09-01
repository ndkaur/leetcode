/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
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

//O(n^2)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int ans= INT_MIN;
        for(int i=0; i<n; i++){
            int pro=1;
            for(int j=i; j<n; j++){
                pro = pro* nums[j];
                ans= max(ans, pro);
            }
        }
        return ans;
    }
};

//O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int ans= nums[0];
        int mx=ans;
        int mn= ans;
        for(int i=1; i<n; i++){
            // if val is -ve then swap as min * min will give max ,  max * min will give more min 
            if(nums[i]<0)
                swap(mx,mn);
            // two options -> start a new array or continue the prev product 
            mx= max(nums[i] , nums[i]*mx);
            mn =  min(nums[i], nums[i]*mn);
            ans = max(ans, mx);
        }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}