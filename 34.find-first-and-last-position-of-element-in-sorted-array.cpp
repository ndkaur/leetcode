/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
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


class Solution { //O(N)
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int f =-1;
        int l =-1;
        for(int i=0; i<n; i++){
            if(nums[i]== target){
                if(f == -1)
                    f = i;
                l = i;
            }
        }
        return {f,l};
    }
};

// first occurence = lower bound = arr[idx] >= target
// last occurence  = upper bound -1 =  arr[idx] > target
class Solution { // 2 O(log N)
public:
    int lowerb(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int ans = n;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]>=target){
                ans = mid;
                r = mid-1;
            }
            else 
                l= mid+1;
        }
        return ans;
    }
    int upperb(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int ans = n;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]>target){
                ans = mid;
                r = mid-1;
            }
            else 
                l= mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = lowerb(nums, target);
        int last = upperb(nums, target);
        // the number does not exist in array then lb will be n
        if(first == n || nums[first]!=target)
            return {-1,-1};
        return {first,  last-1};
    }
};



// so we use to binary search 
//  first search is for tho find the first num equla to target 
// second search is to find the last num equal to the target 


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first =-1;
        int last =-1;
        int l = 0;
        int r = n-1;
        //serching for first occuurence
        while(l<=r){
            int mid  = l+(r-l)/2;
            if(nums[mid]==target){
                first = mid;
                // maybe left side also have some equal elements
                r = mid-1;
            }
            else if(nums[mid]>target){
                r =  mid-1;
            }
            else 
                l = mid+1;
        }
        l = 0;
        r = n-1;
        // last occurence
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                last = mid;
                // maybe right side also have last occurence present
                l = mid+1;
            }
            else if(nums[mid]> target){
                r = mid-1;
            }
            else 
                l = mid+1;
        }
        return {first,last};
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={5,7,7,8,8,10};
    int target= 8;
    vector<int> ans= sol.searchRange(nums, target);
    for(auto it:ans)
        cout<<it<<endl;
    return 0;
}