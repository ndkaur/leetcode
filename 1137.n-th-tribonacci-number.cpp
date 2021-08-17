/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
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
class Solution0 {
public:
    int tribonacci(int n) {
        if(n<2) return n;
        int a=0,b=1,c=1 , d=a+b+c;
        while(n>2){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
            n--;
        }
        return c;
    }
};

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp{0,1,1};
        for(int i=3;i<=n;i++){
            dp[i%3] = dp[i%3]+dp[(i+1)%3]+dp[(i+2)%3];
        }
        return dp[n%3];
    }
};

// if direct multiple of 3 then it will give 0 
// if i+1 remainder will be 1
// if i+2 remainder will be 2 
// and we keep on updating the values of dp[0], dp[1], dp[3]

// @lc code=end


int main(){
    Solution sol;
    int n=25;
    int ans=sol.tribonacci(n);
    cout<<ans;
    return 0;
}