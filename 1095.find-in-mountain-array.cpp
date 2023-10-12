/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
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


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        if(n<3)
            return -1;
        int peak = bspeak(mountainArr, n);
        int left = lsearch(0, peak, target, mountainArr);
        if(left!=-1)
            return left;

        int right = rsearch(peak,n-1, target, mountainArr);
        return right;
    }

    int bspeak(MountainArray &mountainArr, int n){
        int l = 0;
        int r = n-1;
        int ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            // peak -> l<mid>r 
            // but if curr elm mid<r move ahead maybe next elem can be peak 
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                l = mid+1;
                ans = mid+1;
            }
            else 
                r = mid-1;
        }
        return ans;
    }

    int lsearch(int l, int r, int target, MountainArray &mountainArr){
        int ans = -1;
        // not a peak still in increasing order
        while(l<=r){
            int mid = l+(r-l)/2;
            if(mountainArr.get(mid)==target)
                ans = mid;
            if(target<mountainArr.get(mid))
                r = mid-1;
            else 
                l = mid+1;
        }
        return ans;
    }

    int rsearch(int l, int r, int target, MountainArray &mountainArr){
        // not a peak but in decreasing order 1 2 3 6 5 4 3 and mid is at 5
        int ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(mountainArr.get(mid)==target)
                ans = mid;
            if(target < mountainArr.get(mid))
                l = mid+1;
            else 
                r = mid-1;
        }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}