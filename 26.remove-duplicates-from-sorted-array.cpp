/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
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
class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int len =nums.size();
        map<int,int> c;
        for(int i=0;i<len;i++){
            c[nums[i]]++;
        }
        vector<int> out;
        for(auto p:c){
            out.push_back(p.first);
        }
        // return out;
        return c.size();
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        int i=0; // we used two pointers
        for(int j=1;j<n;j++){
            if(nums[j]!=nums[i]){
                i++; //count increased
                nums[i]=nums[j]; // inplace replacemnt for the term 
            }
        }
        return i+1;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    int out=sol.removeDuplicates(nums);
    // print(out);
    cout<<out;
    return 0;
}