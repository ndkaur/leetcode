/*
 * @lc app=leetcode id=1954 lang=cpp
 *
 * [1954] Minimum Garden Perimeter to Collect Enough Apples
 */
#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    long long minimumPerimeter(long long need) {
       long long  int low=0;
        long long  int high=100000;
        while(low<high)
        {
           long long  int n=low-(low-high)/2;
            if((2*(n)*(n+1)*(2*n+1)) < need)
            {
                low=n+1;
            }
            else
            {
                high=n;
            }
        }
        return 8*low;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int need=1;
    int ans = sol.minimumPerimeter(need);
    cout<<ans;
    return 0;
}