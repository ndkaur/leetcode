/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int tsum=0;
        int sum=0;
        for(int i=0;i<n;i++){
            tsum=tsum+nums[i];
        }
        for(int i=0;i<n;i++){
            tsum=tsum-nums[i];
            if(sum==tsum)
                return i;
            sum=sum+nums[i];
        }
        return -1;
        
    
    } 
};


// this solution fails becuse somewhere negatives numbers come in an array 
// class Solution {
// public:
//     int pivotIndex(vector<int>& a) {
//         int n = a.size();
//         if(!n) 
//             return -1;
//         int i = 1, j = n-1;
//         int lsum = a[0], rsum = 0;
//         while(i<j){
//             if(lsum<rsum) lsum+=a[i], ++i;
//             else if(lsum>rsum) rsum+=a[j], --j;
//             if(lsum==rsum) return i;
//         }
//         return -1;
//     }
// };
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,7,3,6,5,6};
    int index;
    index=sol.pivotIndex(nums);
    cout<<index;
    return 0;
}
