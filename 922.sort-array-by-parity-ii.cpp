/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
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
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n=A.size();
        vector<int> odds, evens;
        for(int i=0; i<n; ++i){
            if(A[i]&1) odds.push_back(A[i]);
            else evens.push_back(A[i]);
        }

        // int oi = 0, ei=0;
        // for(int i=0; i<n; ++i){
        //     if(i&1){
        //         A[i] = odds[oi++];
        //     }else{
        //         A[i] = evens[ei++];
        //     }
        // }
        // return A;
    
        for(int i=0; i<n; ++i){
            if(i&1){
                A[i] = odds.back();
                odds.pop_back();
            }else{
                A[i] = evens.back();
                evens.pop_back();
            }
        }
        return A;
    }
};


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n= nums.size();
        for(int i=0,j=1;i<n && j<n;){
            if(nums[i]%2==0){
                i+=2;
            }else if(nums[j]%2==1){
                j+=2;
            }else {
                swap(nums[i],nums[j]);
            }
        }
        return nums;     
    }
};
// @lc code=end
int main(){
    Solution sol;
    vi A={4,2,5,7};
    sol.sortArrayByParityII(A);
    print(A);
    return 0;
}