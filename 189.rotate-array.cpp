/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
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


class Solution0 { // time O(n), space O(n)
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0 || k<=0)
            return;
        
        vector<int> temp = nums;
        
        for(int i=0; i<n; i++){
            nums[(i+k)%n] = temp[i];
        }
    }
};


class Solution1 { // O(N), space = O(1)
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0 || k<=0)
            return;
        // [1,2,3,4,5,6,7], k = 3
        // [5,6,7,1,2,3,4]
        k = k%n;
        // revese first n-k elements //O(k)
        reverse(nums.begin(), nums.begin()+n-k); // 4321 567

        // reverse last n-k elemts //O(n-k)
        reverse(nums.begin()+n-k, nums.end()); // 4321 765

        // reverse complete array  //O(n)
        reverse(nums.begin(), nums.end()); // 5671234
    }
};





class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len =nums.size();
        if(k%len==0)
            return;
        else{
            if(k>len)
                k=k%len;
            
            reverse(nums.begin(),nums.end());
            reverse(nums.begin(),nums.begin()+k);
            reverse(nums.begin()+k , nums.end());
        }
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2,3,4,5,6,7};
    int k ;
    sol.rotate(nums,3);
    print(nums);
    return 0;
}