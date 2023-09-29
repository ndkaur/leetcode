/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
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
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=n-1; // odd
        while(i<j){
            while(i<j && nums[i]%2==0){
                i++;
            }
            while(i<j && nums[j]%2!=0){
                j--;
            }
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int len =A.size();
        vector<int> output;
        for(int i=0;i<len;i++){
            if(A[i]%2==0)
              output.push_back(A[i]);
              
        }
        for(int i=0;i<len;i++){
            if(A[i]%2!=0)
              output.push_back(A[i]);
              
        }
        return output;
    }
};

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n= nums.size();
        int i=0;
        int j=n-1; // will find even 
        while(i<j){
            if(nums[i]%2!=0 && nums[j]%2==0){
                swap(nums[i],nums[j]);
                i++,j--;
            }
            else if(nums[j]%2!=0)
                j--;
            else if(nums[i]%2==0)
                i++;
        }
        return nums;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vi A,output;
    int i;
    A={4,1,3,2};
    output=sol.sortArrayByParity(A);
    print(output);
    // return 0;
}