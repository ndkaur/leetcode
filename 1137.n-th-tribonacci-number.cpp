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
class Solution {
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
// @lc code=end


int main(){
    Solution sol;
    int n=25;
    int ans=sol.tribonacci(n);
    cout<<ans;
    return 0;
}