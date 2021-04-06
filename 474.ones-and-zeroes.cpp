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