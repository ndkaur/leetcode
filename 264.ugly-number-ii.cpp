/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// ugly no which has only the  given factors 

// @lc code=start
//METHOD 1
// class Solution {
// public:
//     int nthUglyNumber(int n) {
//        int count=0;
//        for(int i=1; ;i++){
//            if(is_ugly(i)){
//                count++;
//            }
//            if(count==n)
//                 return i;
//        }
//         return -1;
//     }
//     bool is_ugly(int x){
//         while(x%2==0){
//             x=x/2;
//         }
//         while(x%3==0){
//             x=x/3;
//         }
//         while(x%5==0){
//             x=x/5;
//         }
//         return x==1;
//     }
// };

class Solution0 {
public:
    int nthUglyNumber(int n){
        if(n<=0)    //if the value of n is negative or is zero
            return false;
        if(n==1) 
            return true;

        int t2=0,t3=0,t5=0;
        vector<int> k(n);
        k[0]=1; // 1 is a ugly number
        for(int i=1;i<n;i++){
            k[i]=min(k[t2]*2,min(k[t3]*3,k[t5]*5));// min because to get order in increasing order
            if(k[i]==k[t2]*2)  // to check if it is exactly a multiple of 2
                t2++; //increase the count of 2
            if(k[i]==k[t3]*3)
                t3++;
            if(k[i]==k[t5]*5)
                t5++;
        }       
        return k[n-1]; // zero based indexing
    }
};


class Solution {
public:
    int nthUglyNumber(int n){
        vector<int> dp(n+1);
        dp[1]=1;
        int p2=1;
        int p3=1;
        int p5=1;
        for(int i=2;i<=n;i++){
            int f2= dp[p2]*2;
            int f3= dp[p3]*3;
            int f5 = dp[p5]*5;
            int mn = min(f2, min(f3,f5));
            dp[i]=mn;
            if(mn==f2)
                p2++;
            if(mn==f3)
                p3++;
            if(mn==f5)
                p5++;
        }
        return dp[n];
    }
};

//taking min of values from table of 2, 3,5 and the value taken as min
//  its pointer is moved forward and its table value is increased

// @lc code=end


int main(){
    Solution sol;
    int n=10;
    int ans=sol.nthUglyNumber(n);
    cout<<ans;
    return 0;
}