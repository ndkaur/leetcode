/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
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
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return true;
        int i =0;
        if(i<n-1 && nums[i]<=nums[i+1]){
            while(i<n-1 && nums[i]<=nums[i+1]){
                i++;
            }
            if(i==n-1)
                return true;
        }
        int j =0;
        if(j<n-1 && nums[j]>=nums[j+1]){
            while(j<n-1 && nums[j]>=nums[j+1]){
                j++;
            }
            if(j==n-1)
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool inc = true;
        bool dec = true;
        // increasing check 
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]){ // if decreasing num found anywhere 
                inc = false;
            }
        }
        // decreasing check 
        for(int i=0; i<n-1; i++){
            if(nums[i]<nums[i+1]){ // if increasing found 
                dec = false;
            }
        }

        return inc || dec;  // any one of inc or dec is true return true
    }
};

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n=A.size();
        bool inc =true ,dec=true;
        for(int i=0 ;i<n-1;i++){
            if(A[i]>A[i+1]) inc=false;
            if(A[i]<A[i+1]) dec=false;
            if(inc ==false && dec==false) return false;
        }
        return true;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> A={5,7,8,63,4};
    bool ans=sol.isMonotonic(A);
    cout<<ans;
    return 0;
}
