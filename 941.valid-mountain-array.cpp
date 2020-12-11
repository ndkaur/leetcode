/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
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
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        // for solving bool questions always write bool=false conditions in loops
        // so to return bool=true in the end.

        int n=A.size();
        if(n<3)
            return false;
        int i=0;
        while(i<n && A[i]<A[i+1])  // for checking srictly increasing
            i++;

        if(i==n-1 || i==0)  // if the i has reached end (n-1) that means each i<i+1
            return false;  //strictly decreasing doesnot exist
        
        // for checking strictly decreasing
        while(i<n-1){
            if(A[i]<=A[i+1]) // checking if there is any case when elements are equal
                return false;
            i++;
        }
        return true;
    }
};

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n =arr.size();
        if(n<3) return false;
        int i=0;
        while(i+1<n && arr[i]<arr[i+1]) //check increase
            i++;
        if(i==0 || i==n-1)// peak can be at begin or at end 
            return false;
        while(i+1<n && arr[i]>arr[i+1]) // check decrease
            i++;
        return i==n-1; // i reached last position 
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> A={0,3,2,1};
    bool out=sol.validMountainArray(A);
    cout<<out;
    return 0;
}