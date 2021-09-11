/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
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

// dp -> 
// 1. recursive 
// 2. top down approach 
// 3. bottom up approach 
// 4. optimal 1d array solution 

class Solution0 {
public:
    bool stoneGame(vector<int>& piles) {
        return true; // alex always wins 
    }
};

class Solution1 {        // runtime error
public:                
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        bool turn;
        return game(piles,0,n,turn);
    }
    int game(vector<int>& piles, int start, int end, bool turn){
        if(start>end)
            return false;
        int ans1;
        if(turn){ // alex turn 
            int r1= game(piles,start+1,end,false)+piles[start];
            int r2= game(piles,start,end-1,false)+piles[end];
            ans1= max(r1,r2);
        }
        // lee turn 
        int r1= game(piles,start+1,end,true)-piles[start];
        int r2= game(piles,start,end-1,true)-piles[end];
        int ans2= min(r1,r2);
        return (ans1>ans2);
    }
};  

class Solution2 { // top down approach 
public:
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        bool turn=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return game(piles,0,n-1,turn,dp);
    }
    int game(vector<int>& piles, int start, int end, bool turn,vector<vector<int>>& dp){
        if(start>end)
            return false;
        if(start==end)
            return piles[start];
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        if(turn){ // alex turn 
            int r1= game(piles,start+1,end,false,dp)+piles[start];
            int r2= game(piles,start,end-1,false,dp)+piles[end];
            dp[start][end]= max(r1,r2);
            dp[start][end];
        }
        else { // lee turn 
            int r1= game(piles,start+1,end,true,dp)-piles[start];
            int r2= game(piles,start,end-1,true,dp)-piles[end];
            dp[start][end]= min(r1,r2);
            
        }
        return dp[start][end];
    }
};

class Solution3 { // bottom up 2d 
public:
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        bool turn=0;
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int start=0;start<n-i;start++){
                int end= i+start;
                if(start==end){
                    dp[start][end]= -piles[start];
                    continue;
                }
                if(turn){
                    dp[start][end] = max(dp[start+1][end]+piles[start], dp[start][end-1]+piles[end]);
                }
                else 
                    dp[start][end]= min(dp[start+1][end]-piles[start], dp[start][end-1]-piles[end]);
            }
            turn =!turn;
        }
        return dp[0][n-1];
    }
};

class Solution { // bottom up 1d
public:
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        bool turn =true;
        vector<int> dp(n);
        for(int start=n-1;start>=0;start--){
            for(int end=start;end<n;end++){
                if(start==end){
                    dp[end]=piles[end];
                    continue;
                }
                if(true){
                    dp[end]=max(dp[end]+piles[end] , dp[end-1]+piles[end-1]);
                }
                else 
                    dp[end]=min(dp[end]-piles[end], dp[end-1]-piles[end-1]);
            }
            turn = !turn;
        }
        return dp[n-1];
    }
};


class Solution {
public:
    int dp[501][501];
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        memset(dp,-1,sizeof dp);
        return help(0,n-1,piles);
    }
    int help(int i, int j, vector<int>& piles){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = max(piles[i]-help(i+1,j,piles),piles[j]-help(i,j-1,piles));
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> piles ={6,9,10,5,9,10};
    bool ans = sol.stoneGame(piles);
    cout<<ans;
    return 0;
}