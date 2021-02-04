/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
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
    int hammingWeight(uint32_t n) {
        int c=0;
        for(int i=0;i<32;i++){
            if((n>>i)& 1)
                c++;
        }
        return c;
    }
};
// @lc code=end


int main(){
    Solution sol;
    uint32_t n = 0b11111111111111111111111111111101;
    int count = sol.hammingWeight(n);
    cout<<count;
    return 0;
}