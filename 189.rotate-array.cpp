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