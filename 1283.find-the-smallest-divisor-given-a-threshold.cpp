/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
// class Solution {
// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int n = nums.size();
//         int mx = *max_element(nums.begin(), nums.end());
//         for(int d=1;d<=mx;d++){
//             int sum = find_sum(nums,d);
//             if(sum<=threshold) 
//                 return d;
//         }
//         return -1;
//     }

//     int find_sum(vi &nums, int d){
//         int sum = 0;
//         for(auto x: nums){
//             int ans = (x + d-1)/d;
//             sum+=ans;
//         }
//         return sum;
//     }
// };
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=0;
        int r= *max_element(nums.begin(),nums.end())+1;
        int res=r;
        while(l+1<r){
            int mid = (l+(r-l)/2);
            int sum=0;
            for(auto x:nums){
                int ans = (x+ (mid-1))/mid;
                sum=sum+ans;
            }
            if(sum<=threshold){
                res=mid;
                r=mid;
            }
            else 
                l=mid;
        }
        return res;
    }
};

// @lc code=end


int main(){
    Solution sol; 
    vector<int> nums= {2,3,5,7,11}; 
    int th = 11; 
    int out;
    out = sol.smallestDivisor(nums,th); 
    deb(out);
    return 0;
}