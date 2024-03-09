/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
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

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid =l+(r-l)/2;
            if((mid==0 || arr[mid-1]<arr[mid]) && ( mid==n-1 || arr[mid]>arr[mid+1]))
                return mid;
            else if(mid<n && arr[mid]<arr[mid+1]){
                l = mid+1;
            }
            else 
                r= mid-1;
        }
        return -1;
    }
};


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid =l+(r-l)/2;
            if((mid==0 || arr[mid-1]<arr[mid]) && ( mid==n-1 || arr[mid]>arr[mid+1]))
                return mid;
            if(mid<n && arr[mid]<arr[mid+1]){
                l = mid+1;
            }
            else 
                r= mid-1;
        }
        return l;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n=a.size();
        int l=0,r=n-1;
        while(l<r){
            int mid =l+(r-l)/2;
            if(a[mid]<a[mid+1])
                l=mid+1;
            else if(a[mid]>a[mid+1])
                r=mid;
        }
        // return r;
        return l;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={0,2,1,0};
    int out=sol.peakIndexInMountainArray(a);
    cout<<out;
    return 0;
}