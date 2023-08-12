/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
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

class Solution { // O(N) , sp->O(N)
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        // 1 2 3 4
        // left = 1 1 2 6 
        // right= 24 12 4 1
        vector<int> left(n);
        left[0] =1;
        vector<int> right(n);
        right[n-1] =1;
        vector<int> ans(n);
        for(int i=1; i<n; i++){
            left[i] = left[i-1]*nums[i-1];
        }
        for(int i=n-2; i>=0; i--){
            right[i] = right[i+1]*nums[i+1];
        }
        for(int i=0; i<n; i++){
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};
// 1 2 3 4
// 1 1 2 6
// right going n-1 
// 24  12   8 6

class Solution { //O(n) 
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n,0);
        
        int pro=1; // total product
        int zcnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]) // findinf pro of lememts excpet including 0 
                pro *= nums[i];
            if(nums[i]==0)
                zcnt++;
        }
        if(zcnt>1) // more than 1 zeros exist sot ans array will be filled with 0
            return ans;
       for(int i=0;i<n;i++){
           if(zcnt==0){  // no zero exist so use prefix product technique
               ans[i] = (pro/nums[i]);
           }
           else // only one 0 exist so the ans will be the product of rest of the elements
                ans[i] = nums[i] ? 0 : pro;
       }
       return ans;
    }
};


class Solution { //O(n)  , O(n)
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();

        vector<int> pre(n);
        int pro=1;
        for(int i=0;i<n;i++){
            pro *=nums[i];
            pref[i]= pro;
        }

        vector<int> suf(n);
        int p=1;
        for(int i=n-1;i>=0;i--){
            p *= nums[i];
            suf[i] = p;
        }

        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            // if i ->for case when i=0  
            // i<n-1 -> for case i<n 
            ans[i] = (i ? pref[i-1] :1) * (i+1 < n ? suf[i+1] : 1);
        }
        return ans;
    }
};


// solving in constant space 
class Solution { //O(n)
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        int pro=1;
        int zcnt = count(nums.begin(), nums.end(),0);
        if(zcnt>1) return vector<int>(n);
        for(auto num:nums){
            if(num)
                pro= pro* num;
        }
        for(auto& num:nums){
            if(zcnt) // only one zero exists
                num = num ? 0 : pro;
            else 
                num = pro/ num;
        }
        return nums;
    }
};

// @lc code=end



int main(){

    return 0;
}