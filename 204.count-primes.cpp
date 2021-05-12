/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
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
class Solution0 {
public:
    int countPrimes(int n) {
        int count=0;
        if(n<=2) return 0;
        for(int i=1;i<n;i++){
            if(isPrime(i))
                count++;
        }
        return count;
    }
    bool isPrime(int num){
        if(num<=1) return false;
        for(int i=2;i*i <= num ; i++){
            if(num % i ==0) return false;
        }
        return true;
    }
};  // time limit exceeded

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int count=0;
        vector<bool> isPrime(n);
        for(int i=2;i<n;i++)
            isPrime[i] =true;// marked every position as true
        for(int i=2; i*i <n ;i++){  // going till n^2
            if(!isPrime[i]) // not prime 
                continue;
            for(int j=i*i ;j<n;j+=i){ // fills all the factors and left with prime nos
                isPrime[j] =false;
            }
        }
        for(int i=2;i<n;i++)
            if(isPrime[i]) // check if marked i is prime then count++
                count++;
        return count;                
    }
};

// @lc code=end


int main(){
    Solution sol;
    int n=10;
    int ans = sol.countPrimes(n);
    cout<<ans;
    return 0;
}