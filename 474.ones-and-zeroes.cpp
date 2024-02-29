/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
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
    pair<int,int> count(string s){
        int one = 0;
        int zero = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1')
                one++;
            else 
                zero++;
        }
        return {one,zero};
    }
    int solve(int i, int zero, int one, int& mxzero, int& mxone, vector<string>& strs, vector<vector<vector<int>>>&dp){
        int n= strs.size();
        if(i>=n)
            return 0;
        if(one>mxone || zero>mxzero)
            return 0;
        
        if(dp[i][zero][one]!=-1)
            return dp[i][zero][one];
        // {one, zero}
        pair<int,int> cnt = count(strs[i]);

        int picknone =0, pickall=0, notPick = 0;
        //  atmost -> curr cnt <= mxcnt
        if(one+cnt.first<=mxone && zero + cnt.second <= mxzero){
            pickall = 1+solve(i+1, zero+cnt.second,one+cnt.first, mxzero, mxone, strs, dp);
            picknone = solve(i+1,zero, one, mxzero, mxone, strs, dp);
        }
        else{
            notPick = solve(i+1, zero, one, mxzero, mxone, strs, dp);
        }
        return dp[i][zero][one]= max({picknone, pickall, notPick});
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int mxzero = m;
        int mxone = n;
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1,-1)));
        return solve(0,0,0, mxzero, mxone, strs, dp);
    }
};


class Solution {
public:
    int solve(int i, int mxzero, int mxone, vector<string>& strs, vector<vector<vector<int>>>&dp){
        int n= strs.size();
        if(i>=n)
            return 0;
        
        if(dp[i][mxzero][mxone]!=-1)
            return dp[i][mxzero][mxone];
        
        int zc  = count(strs[i].begin(), strs[i].end(), '0');
        int oc = strs[i].size()-zc;

        //  atmost -> curr cnt <= mxcnt
        if(mxzero - zc>=0 && mxone - oc>=0){
            return dp[i][mxzero][mxone] = max(1+solve(i+1, mxzero-zc, mxone-oc, strs, dp), solve(i+1, mxzero, mxone, strs, dp));
        }
        else{
           return dp[i][mxzero][mxone] = solve(i+1, mxzero, mxone, strs, dp);
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1,-1)));
        return solve(0,m, n, strs, dp);
    }
};


class Solution0 {
    void max_self(int &a, int b){
        if(a<b)
            a=b;
    }
public:
    int findMaxForm(vector<string>& strs, int Z, int O) {
        int n= strs.size();
        vector<vector<int>> count;
        for(auto s:strs){
            int ze=0,on=0;
            for(auto x:s){
                if(x=='1')
                    on++;
                else 
                    ze++;
            }
            count.push_back({ze,on});
        }
        vector<vector<int>> dp(Z+1,vector<int>(O+1));
        for(int i=1;i<n+1;i++){
            for(int z=Z;z>=0;z--){
                for(int o=O;o>=0;o--){
                    int ze_cnt = count[i-1][0];
                    int on_cnt = count[i-1][1];
                    if(z>=ze_cnt && o>=on_cnt){
                        max_self(dp[z][o], 1+ dp[z-ze_cnt][o-on_cnt]);
                    }
                }
            }
        }
        return dp[Z][O];
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int Z, int O) {
        int n= strs.size();
        vector<vector<int>> dp(Z+1,vector<int>(O+1));
        int cnt_zero , cnt_one;
        for(auto &s:strs){
            cnt_zero=cnt_one=0;
            for(auto x:s){
                if(x=='1')
                    cnt_one++;
                else 
                    cnt_zero++;
            }
        
            for(int i=Z;i>=cnt_zero;i--){
                for(int j=O;j>=cnt_one;j--){
                    dp[i][j]=max(dp[i][j], 1+dp[i-cnt_zero][j-cnt_one]);
                }
            }
        }
        return dp[Z][O];
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<string> str={"10","0001","1","0"};
    int Z=5;
    int O=3;
    int ans =sol.findMaxForm(str,Z,O);
    cout<<ans;
    return 0;
}