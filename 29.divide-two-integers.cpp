/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
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
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        if(dividend==INT_MIN && divisor==1)
            return INT_MIN;
        
        // big =10, small=3 
        // 10-3= 7-3 = 4-3 = 1 
        //  so we used 3 times 3 to divide 10
        long long big = abs(dividend);
        long long small = abs(divisor);

        int ans = 0;
        while(small<=big){
            long long sum = small;
            long long cnt = 1;
            while(sum <= big-sum){
                sum+=sum;
                cnt+=cnt;
            }
            ans += cnt;
            big -= sum;
        }

        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
            return -ans;
        return ans;
    }
};


// @lc code=end


int main(){

    return 0;
}