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