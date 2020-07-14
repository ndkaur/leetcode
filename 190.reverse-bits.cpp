/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
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
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        for(int i=0;i<32;i++){
            result<<=1;
            if(n&1)
                result++;
            n>>=1;
        }
        return result;
    }
};
// @lc code=end

int main(){
    Solution sol; 
    uint32_t  n = 43261596;
    uint32_t out = sol.reverseBits(n);
    cout<<out<<"\n";
    return 0;
}