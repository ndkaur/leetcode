/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
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

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         vector<int> ans;
//         map<int,int> count;
//         for(auto i:nums){
//             count[i]++;
//         }
//         for(auto ptr:count){
//             if(ptr.second==1)
//                 ans.push_back(ptr.first);
//         }
//         return ans;
//     }
// };
// @lc code=end
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums){
        int xy=0;
        for(int n:nums)
            xy=xy^n;

        xy = xy & (-xy);
        vector<int> result={0,0};
        for(int n:nums){
            if(xy & n) 
                result[0]=result[0]^n;
            else 
                result[1]=result[1]^n;
        }
        return result;
    }
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for(auto x: nums) xr^=x;
        int a = 0,  b = 0;
        int first_set_bit = 0;
        while(!(xr&1)){
            first_set_bit++;
            xr>>=1;
        }
        for(auto x: nums){
            if((x>>first_set_bit)&1)
                a^=x;
            else 
                b^=x;
        }
        return {a,b};
    }   
};

int main(){
    Solution sol;
    vector<int> nums={1,2,1,2,3,5};
    vector<int> ans=sol.singleNumber(nums);
    print(ans);
    return 0;
}