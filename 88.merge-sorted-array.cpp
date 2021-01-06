/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
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
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m+n-1; // last pos of nums1 
        //to put greatest number in the end 
        while(m && n){
            if(nums1[m-1]>nums2[n-1]){
                nums1[index--] = nums1[--m];
            }
            else {
                nums1[index--]=nums2[--n];
            }
        }
        while(m)
            nums1[index--]=nums1[--m];
        while(n)
            nums1[index--]=nums2[--n];
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums1={1,2,3,0,0,0};
    int m=3;
    vector<int> nums2 ={2,5,6};
    int n=3;
    sol.merge(nums1,m,nums2,n);
    print(nums1);
    return 0;
}