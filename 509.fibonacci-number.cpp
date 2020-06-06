/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
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
    int fib(int N) {
        vector<int> F(51);
        F[0] = 0;
        F[1] = 1;
        for(int i=2; i<50; i++)
            F[i] = F[i-1] + F[i-2];
        
        return F[N];
    }
};
    
// @lc code=end


int main(){
    Solution sol;
    int out = sol.fib(4);
     cout<<out<<endl;
    return 0;
}