/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
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
    int hammingDistance(int x, int y) {
        int count=0; //for counting the no of times the bits of x and y differs. 
        int z=x^y; // to find out where the bits of x and y differs.
        while(z>0){ 
            count=count+(z&1);// used & to check if the last bit is on or off.
            z=z>>1; //to remove the last bit and to move the n further to next bit
        }
        return count;
    }
};
// XOR supports difference
// x=1, 0 0 0 1 
// x=4, 0 1 0 0
//...............
//z=x^y,0 1 0 1
// z&1, 0 1 0 1  count ++;
//z=z>>1, 0 1 0

// @lc code=end
int main(){
    Solution sol;
    int x=1,y=4;
    int count=sol.hammingDistance(x,y);
    cout<<count;
    return 0;
}