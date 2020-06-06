/*
 * @lc app=leetcode id=1313 lang=cpp
 *
 * [1313] Decompress Run-Length Encoded List
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int len= nums.size();

        vector<int> out;
        for(int i=0; i<len; i+=2){
            int freq = nums[i];
            int val = nums[i+1];
            
            for(int j=0; j<freq; j++){
                out.push_back(val);
            }
        }
        return out;
    }
};
// @lc code=end 
int main(){
    Solution sol; vi nums, out;
    nums = {1,2,3,4};
    out = sol.decompressRLElist(nums); 
    print(out);
    return 0;
}

