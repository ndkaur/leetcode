/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
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


// o(n) -> linear search in whole array 

// it is sure that one side must be sorted on both sides of mid 
// find that sorted side then apply bs on it 
class Solution { //O(logn)
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int l= 0;
        int r= n-1;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target) 
                return mid;

            // check if left half from mid is sorted 
            if(nums[l] <= nums[mid]){
                // check if target lie in left half  l< t< m
                if(nums[l]<= target && target<= nums[mid])
                    r= mid-1;
                else 
                    l= mid+1;
            }
            else{ // right half sorted 
                // check if target lie on the right half of mid  m<t<r
                if(nums[mid] <= target && target<= nums[r]){
                    l= mid+1;
                }
                else 
                    r= mid-1;
            }
        }
        return -1;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> nums= {4,5,6,7,0,1,2};
    int target =0;
    int ans = sol.search(nums, target);
    cout<<ans;
    return 0;
}