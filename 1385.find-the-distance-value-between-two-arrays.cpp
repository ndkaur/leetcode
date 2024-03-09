/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start


class Solution0 {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int cnt =0;
        for(int i=0; i<n; i++){
            bool found = false;
            for(int j=0; j<m && !found; j++){
                if(abs(arr1[i]-arr2[j]) <= d){
                    found = true;
                }
            }
            if(!found)
                cnt++;
        }
        return cnt;
    }
};


class Solution {
public:
    bool isValid(vector<int>& arr, int target, int d){
        int l = 0;
        int r = arr.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(abs(arr[mid]-target)<=d){
                return false;
            }
            else if(arr[mid]<target){
                l = mid+1;
            }
            else 
                r = mid-1;
        }
        return true;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int cnt =0;
        sort(arr2.begin(), arr2.end());

        for(auto num:arr1){
            if(isValid(arr2, num, d)){
                cnt++;
            }
        }
        return cnt;
    }
};


// @lc code=end
int main(){
    Solution sol;
    vector<int> arr1={4,-3,-7,0,-10},arr2={10};
    int count=sol.findTheDistanceValue(arr1,arr2,69);
    cout<<count;
    return 0;
}