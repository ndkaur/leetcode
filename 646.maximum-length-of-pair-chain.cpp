/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
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
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(); // rows height 
        sort(pairs.begin(),pairs.end());
        vector<int> dp(n+1,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                // pairs[0][1]<pairs[1][0]
                if(pairs[j][1]<pairs[i][0])
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        int count =0; // to find max element of dp array 
        for(auto x:dp){
            if(x>count) count=x;
        }
        return count;
    }
};


//O(n*m)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int m = pairs[0].size();
        sort(pairs.begin(), pairs.end());
       // lis 
       int mx =0;
       vector<int> dp(n,1);
       for(int i=0; i<n; i++){ //next =i
           for(int j=0; j<i; j++){ // prev =j
               if(pairs[j][1] < pairs[i][0] && dp[i] < 1+dp[j]){
                   dp[i] = 1+dp[j];
               }
           }
            mx= max(mx, dp[i]);
       }
       return mx;
    }
};

//O(nlogn)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(); // rows height 
        sort(pairs.begin(),pairs.end(),cmp);
        int curr= INT_MIN; 
        int count=0;
        for(auto pair:pairs){
            if(curr<pair[0]){
                curr=pair[1];
                count++ ;
            }
        }
        return count;
    }
    static bool cmp(vector<int>& a , vector<int>& b){
        if(a[1]==b[1]) // 2nd element of both same 
            return a[0]<b[0];
        return a[1]<b[1];
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> pairs={{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}};
    int ans = sol.findLongestChain(pairs);
    cout<<ans;
    return 0;
}