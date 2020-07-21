/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
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
    bool isPerfectSquare(int num) {
        if(num<1)
            return false;
        if(num==1)
            return true;
        int l=1;
        int r=num;
        while(l<=r){
            long long m=l+(r-l)/2;
            if(m*m==num)
                return true;
            else if(m*m>num)
                r=m-1;
            else if(m*m<num)
                l=m+1;
        }
        return false;
    }
};
// @lc code=end
int main(){
    Solution sol;
    int num=104976;
    bool out=sol.isPerfectSquare(num);
    cout<<out;
    return 0;
}