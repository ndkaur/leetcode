/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
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
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(arr[i]<=k)
                k++;
            else 
                break;
        }
        return k;
    }
};


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
       
        // array of missing number till that index 
        // 0 1 2 3 4 <- idx
        // 2 3 4 7 11  <- arr
        // 1 1 1 3  6  <- missing cnt= arr[i]-i-1
        // l   m    r   k=5 , 1<5 so move l 
        // m= 3<5 , l++
        // m=6 6>5 r-- 
        // l =4 idx, r=3 idx
        // now we know the range , we need to find the val of missing number btwe that range -> 7-11
        // kth  missing val = arr[r]+more = 7 + more   , more = k-missing elm at that idx = 5-3 = 2
        //  7+2 = 9  , arr[h] + k -(arr[high]-high-1) = high +1+k = low+k
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid] < mid+k+1)
                l = mid+1;
            else 
                r = mid-1;
        }
        return l+k; 
    }
};

// binary search 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l =0;
        int r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            // dp binary search on no of missing elements
            int miss_no = arr[mid]-mid-1;
            if(miss_no < k){
                l = mid+1;
            }
            else 
                r = mid-1;
        }
        // kth  missing val = arr[r]+more = 7 + more   , more = k-missing elm at that idx = 5-3 = 2
        //  7+2 = 9  , arr[h] + k -(arr[high]-high-1) = high +1+k = low+k
        return k+r+1;
    }
};
//idx        0 1 2 3 4      
//arr =      2 3 4 7 11
// missing = 1 1 1 3 6

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>nums(2001,0);
        for(int i=0; i<n; i++){
            nums[arr[i]] = 1;
        }
        int ans = 1;
        int idx = 0; // cnt of missing nums
        for(int i=1; i<2001; i++){
            if(nums[i] == 0)
                idx++;
            if(idx==k){
                ans = i;
                break;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l =0;
        int r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid] < mid+k+1)
                l = mid+1;
            else 
                r = mid-1;
        }
        return l+k; 
    }
};

// @lc code=end


int main(){

    return 0;
}