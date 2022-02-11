/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
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
//  same as 1011. capacity to ship packages 
class Solution { // binary search 
public:
    int splitArray(vector<int>& nums, int m) {
        int n= nums.size();
        int sum=0;
        int mx=0;
        for(int i=0;i<n;i++){
            sum+= nums[i];
            mx= max(mx,nums[i]);
        }
        int l=mx;
        int h=sum;
        int ans =0;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(isPossible(nums,m,mid)==true){
                h= mid-1;
                ans= mid;
            }
            else {
                l= mid+1;
            }
        }
        return ans;
    }
    bool isPossible(vector<int>&nums, int m, int mid){
        int n=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
            if(sum>mid){
                n++;
                sum= nums[i];
            }
        }
        if(n<=m) return true;
        return false;
    }
};

// time complexity-> log(sum)*n; 
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={7,2,5,10,8};
    int m=2;
    int ans= sol.splitArray(nums,m);
    cout<<ans;
    return 0;
}