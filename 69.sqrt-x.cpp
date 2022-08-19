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

// binary search
class Solution0 {
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

//linear search 
class Solution1 {
public:
    int mySqrt(int x) {
        long long y=0;
        while(y*y<=x) y++;
        return y-1;
    }
}; 

class Solution { //O(logn)  O(1)
public:
    int mySqrt(int x) {
        long long l=0;
        long long r=INT_MAX;
        long long ans;
        while(l<=r){
            long long m= l+(r-l)/2;
            if(m*m<=x){
                ans =m;
                l=m+1;
            }else {
                r=m-1;
            }
        }
        return ans;
    }
};

//  time complexity = O(under root of x)
// @lc code=end


int main(){
    Solution sol;
    int x =5;
    int ans=sol.mySqrt(x);
    cout<<ans;
    return 0;
}