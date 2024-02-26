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

class Solution {
public:
    double myPow(double value, long power) {
        double result= 1.0;
        long long pow = power;
        if(pow<1){ // -ve power
            pow = abs(pow);
        }
        while(pow){
            if(pow%2){ // odd
                // 4^5 = odd power =5 -> so value * res  and power -1 
                // 4 * (4)^4 
                result = result * value;
                pow = pow -1;
            }
            else{ // even 
                // 2^ 10 = even power 10 -> so power half and value *value 
                // (2 * 2)^5  = (4)^5 
                value = value*value;
                pow = pow/2;
            }
        }
        if(power<0){ // -ve then 1/val
            result = (double)(1.0) / (double)(result);
        }
        return result;
    }
};

class Solution {
public:
    double myPow(double value, long power) {
        double result= 1.0;
        long long newPower = power; // cause after converting -ve power to +ve
        // the range of int increases 
        if(newPower<0){ //-ve power
            newPower = -1*newPower;
        }
        while(newPower){
            if(newPower%2){ // odd power
                result = result * value;
                newPower = newPower-1;
            }
            else{ // even power 
                value = value * value;
                newPower = newPower/2;
            }
        }
        if(power<0)
            result = (double)(1.0) / (double)(result);
        return result;
    }
};

// 2^ 10 = even power 10 -> so power half and value *value 
// (2 * 2)^5  = (4)^5 
// 4^5 = odd power =5 -> so value * res  and power -1 
// 4 * (4)^4 
//4^4 = even power -> value*value and power/2
//  (4*4)^2 = (16)^2
//16^2 =  (16*16) = 256 

// 4*256 = 1024


// brute force 
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        while (n) {
            if (n % 2) res = n > 0 ? res * x : res / x;
            x = x * x;
            n /= 2;
        }
        return res;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0){
            return 1;
        }
        if (n < 0) { 
            n = abs(n);
            x = 1/x;
        }
        if(n%2==0){
            return myPow(x*x,n/2);
        
        }else{
            return x*myPow(x*x,n/2);
        }
    }
};


// simple n easy 
class Solution { //O(logn)
public:
    double myPow(double val, int pow) {
        if(pow==0)
            return 1;
        if(pow<0){
            val = 1/val;
            pow = abs(pow);
        }
        double res=1;
        while(pow>0){
            if(pow%2==0){
                pow = pow/2;
                val = val*val;
            }
            else{
                pow = pow-1;
                res = res *val;
            }
        }
        return res;
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