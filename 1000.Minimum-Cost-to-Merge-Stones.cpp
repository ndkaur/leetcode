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



//  k piles pick them up and at the end we are remining with only 1 pile 
// so first check is can we merge all piles into 1 pile at the end ? 
// n piles , k to be merged
// 1st time merging k piles -> 
// remining piles = k piles that we took will lead to 1 pile so n-(k-1)
// eg = n=5, k=3 , so  1,2,sum = 3 remining 
// 2nd time picking k piles = n-(k-1)-(k-1) .. 
// so on a t the end last time 1 len will be reamining 
// N - total merges = 1
// N - (merge*(k-1)) = 1
// N - 1 = merge * (k-1)
// N-1 / (k-1) = merge 
// so finally 
// if((n-1)%(k-1) == 0) then only we can do merging.

// we need range sum so use prefix sum 
// prefix sum(i->j) = sum(j)-sum(i-1);  

// Also, before calculating cost : for every range we will check, if we can merge this or not, to check -> use formula = (n-1) % (k-1)
// if((j-i)%(piles-1) == 0) here j - i = current range and piles is k.


// so when we use k piles reming will the the not used piles and 1 piles extra from the compilation 
// so the for loop will be incremented by k = k+piles-1
// eg = k=3 , 2 piles will be delted and we must incremnet pointer using next k valid piles , we can also include the pile which we got from curr result  
// we need to skip from array , k we used + curr piles we picked -1 

// now reminang part -> think like mcm problem 
// subproblem -> f(i,k) + f(k+1,jfs)


// recursion tle 
class Solution0 { 
public:
    int f(int i, int j, int piles, vector<int>& stones, vector<int>& prefixSum){
        int n = stones.size();
        if(i>=j)
            return 0;
        
        int mn = INT_MAX;
        for(int k=i; k<j; k= k+piles-1){
            int temp = f(i, k, piles, stones, prefixSum) + f(k+1, j, piles, stones, prefixSum);
            mn = min(mn, temp);
        }

        // now we cant merge that means add the sum
        if((j-i)%(piles-1)==0)
            mn += prefixSum[j+1]-prefixSum[i];
        
        return mn;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        // sum[i->j] =  sum[j]-sum[i-1]
    // if we add 0 in prefix sum array then sum[i->j] = sum[j+1]-sum[i]
        vector<int> prefixSum = {0};
        prefixSum[0] = stones[0];
        for(int stone:stones){
            prefixSum.push_back(prefixSum.back()+stone);
        }

        // base case using the formula , case when not possible 
        if((n-1)%(k-1)!=0)
            return -1;

        // i, j, k , stones
        return f(0, n-1, k, stones, prefixSum);
    }
};


// memoization
class Solution1 {
public:
    int f(int i, int j, int piles, vector<int>& stones, vector<int>& prefixSum, vector<vector<int>>& dp){
        int n = stones.size();
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        int mn = INT_MAX;
        for(int k=i; k<j; k= k+piles-1){
            int temp = f(i, k, piles, stones, prefixSum, dp) + f(k+1, j, piles, stones, prefixSum, dp);
            mn = min(mn, temp);
        }

        // now we cant merge that means add the sum
        if((j-i)%(piles-1)==0)
            mn += prefixSum[j+1]-prefixSum[i];
        
        return dp[i][j] = mn;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        // sum[i->j] =  sum[j]-sum[i-1]
    // if we add 0 in prefix sum array then sum[i->j] = sum[j+1]-sum[i]
        vector<int> prefixSum = {0};
        prefixSum[0] = stones[0];
        for(int stone:stones){
            prefixSum.push_back(prefixSum.back()+stone);
        }

        // base case using the formula , case when not possible 
        if((n-1)%(k-1)!=0)
            return -1;

        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));

        // i, j, k , stones
        return f(0, n-1, k, stones, prefixSum, dp);
    }
};



// tabulation
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        // sum[i->j] =  sum[j]-sum[i-1]
    // if we add 0 in prefix sum array then sum[i->j] = sum[j+1]-sum[i]
        vector<int> prefixSum = {0};
        prefixSum[0] = stones[0];
        for(int stone:stones){
            prefixSum.push_back(prefixSum.back()+stone);
        }

        // base case using the formula , case when not possible 
        if((n-1)%(k-1)!=0)
            return -1;

        vector<vector<int>>dp(n+1, vector<int>(n+1,0));

        int piles = k;

        // window of i->j
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                int mn = INT_MAX;
                for(int k=i; k<j; k= k+piles-1){
                    int temp = dp[i][k]+ dp[k+1][j];
                    mn = min(mn, temp);
                }

                // now we cant merge that means add the sum
                if((j-i)%(piles-1)==0)
                    mn += prefixSum[j+1]-prefixSum[i];
                
                dp[i][j] = mn;
            }
        }
        // i, j, k , stones
        return dp[0][n-1];
    }
};



int main(){

    return 0;
}