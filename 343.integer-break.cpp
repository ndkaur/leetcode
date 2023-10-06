/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
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
class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int product =1;
        while(n>4){
            product *=3;
            n= n-3;
        }
        product *= n;
        return product;
    }
};

// using dp 
// so for num = 1 , we cant break ans = 1
// for num =2 , 1+1 = 1*1 = 1 
// num = 3, 2+1 = 1*2 = 2 max 
// for num =4 => (1+3) ,(2+2) , (3+1) 
// further breaking each pair ->  there are 4 possibilities for each pair (a,b)
// 1. we cant break both so take their product -> a*b

// 2. we can break a , so we need max value of a which is stored in dp 
//   so dp[a] * b 

// 3. we can break b,so take max values of so a * dp[b]

// 4. we can break both a and b , dp[a]*dp[b]

// simply taking what its values in the dp 

class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(100);
        dp[1]=1;
        dp[2]=1; 
        dp[3]=2;
        for(int i=4; i<=n; i++){
            //breaking the num 
            // eg = 4 -> (1,3) (2,2) (3,1)
            int num = i; // num=4
            for(int j=1; j<=num; j++){
                int a = j;
                int b = num-a; // 4-1=3, 4-2=2 , 4-3=1
                // no taking maximum of all 4 cases 
                dp[i] = max({dp[i], a*b , dp[a]*b, a*dp[b],  dp[a]*dp[b]});
            }
        }
        return dp[n];
    }
};


// @lc code=end


int main(){
    Solution sol;
    int n=10;
    int ans = sol.integerBreak(n);
    cout<<ans;
    return 0;
}

// 3->2
// 4->4  value of 4 is 4 so simply prodcut into n 
// 5->6  //  the product is always a factor of 3 
// 6->9  // we set product as 1 
// 7->12 //  continue with while loop 
// 8->18   multiply the product with 3 
// 9->27  and reduce the n by subtracting 3 
// 10->36
// 11->54
// 12->81 