/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int product =1;
        while(n>4){
            product *=3;
            n= n-3;
        }
        product *= n;
        return product;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n=10;
    int ans = sol.integerBreak(n);
    cout<<ans;
    return 0;
}

// 3->2
// 4->4  value of 4 is 4 so simply prodcut into n 
// 5->6  //  the product is always a factor of 3 
// 6->9  // we set product as 1 
// 7->12 //  continue with while loop 
// 8->18   multiply the product with 3 
// 9->27  and reduce the n by subtracting 3 
// 10->36
// 11->54
// 12->81 