/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
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
    double myPow(double value, long power) {
        double result= 1.0;
        if(power<0){ // if negative
            value=1/value; // x^-1= 1/x
            power= abs(power);// to convert power into positive
        }
        while(power){
            if(power&1) // check if bit is on or off
                result=result*value; // the main ans is result
            value=value*value; // if on or off , value must increase
            power>>=1; // removing the current bit by right shift
        }
        return result;
    }
};

// @lc code=end


int main(){
    Solution sol;
    double value=2;
    long power=-2;
    double result=sol.myPow(value,power);
    cout<<result;
    return 0;
}