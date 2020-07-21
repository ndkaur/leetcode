/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
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
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int r=n;
        while(l<r){
            int m=l+(r-l)/2;
            if(isBadVersion(mid))
                right=mid;
            else 
                left=mid+1;
        }
        return right;
    }
};
// @lc code=end


int main(){

    return 0;
}