/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
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
class Solution {
public:
    int mySqrt(int x){
        if(x<2)
            return x;
        int left=1,right=x;
        while(left<right){
            long long mid=left+(right-left)/2;
            if(mid*mid==x)
                return mid;
            else if(mid*mid>x)
                right=mid;
            else 
                left=mid+1;
        }
        return left-1;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int x =5;
    int ans=sol.mySqrt(x);
    cout<<ans;
    return 0;
}