  /*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
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
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        for(int i=1;i<=num;i++){
        //    ans[i]=ans[i/2]+ i%2; // method 1
        //    ans[i] = ans[i&(i-1)]+1; // method2
            if(i%2==0)
                ans[i] = ans[i/2];
            else 
                ans[i] = ans[i/2]+1; // method 3
        }
        return ans;
    } // o(n)
};

class Solution {
public:
    vector<int> countBits(int n) {
        int ptr =1;
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++){
            if(ptr*2 ==i)
                ptr =ptr *2;
            dp[i] = dp[i-ptr]+1;
        }
        return dp;
    } // o(n)
};

//  0 1 2 3   4 5 6 7   8 9 10 11   12 13 14 15    16 17 18 19 
//  0 1 1 2   1 2 2 3   1 2 2  3    2  3  3  4     1  2  2  3  // no of 1's 
   
// dp[0] =0 
// dp[1] = 1   dp[1-1] +1 
// dp[2] = 1   dp[2-2] +1   2-2  ptr * 2 == i
// dp[3] = 2   dp[ 3-2]+1 
// dp[4] = 1   dp[4-4] +1   4-4  ptr *2 == i
// dp[5] = 2   dp[5-4]+1 
// dp[6] = 2    dp[6-4]+1
// dp[7] = 3    dp[7-4] +1
// dp[8] = 1   dp[8-8]+1    8-8 ptr *2 == i


// O(nlogn)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int cnt=0;
            int num=i;
            while(num!=0){
                cnt+= num % 2;
                num = num / 2;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};



// let X = 7 and Y = 3
// then 7 / 2 = 3;

// 7 -> 1 1 1 number of set bit are 3
// 3 -> 0 1 1 number of set bit are 2


// X = 12 and y = 6
// then 12 / 2 = 6;

// 12 -> 1100 number of set bit are 2
// 6 -> 0110 number of set bit are 2


//  conclusion -> no of set bits will be equal to the set bits of its half + if even so add 0 if odd add 1
class Solution { // O(N)
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++){
            ans[i]= ans[i/2] + i%2;
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int num=5;
    vector<int> ans =sol.countBits(num);
    print(ans);
    return 0;
} 