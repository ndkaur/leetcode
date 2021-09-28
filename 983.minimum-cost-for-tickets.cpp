/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
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

 

// bottom up approach 
class Solution0 {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n= days.size();
        vector<int> dp(n+1);
        for(int i=n-1;i>=0;i--){
            int d7=i,d30=i;
            while(d7<n && days[d7]<days[i]+7)
                d7++;
            while(d30<n && days[d30]< days[i]+30)
                d30++;
            dp[i] = min ({costs[0]+dp[i+1], costs[1]+dp[d7] , costs[2]+dp[d30] });
        }
        return dp[0];
    }
}; 


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n= days.size();
        vector<int> dp(366);
        vector<bool> trequ(366);
        for(auto x:days)  trequ[x]=1;
        for(int i=1;i<366;i++){
            
            if(trequ[i]){
                dp[i] = dp[i-1] + costs[0];
                dp[i]= min(dp[i],(i-7>=0 ? dp[i-7]:0)+ costs[1]);
                dp[i] = min(dp[i],(i-30>=0 ? dp[i-30]:0)+costs[2]);
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[365];
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> d= {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> c ={2,7,15};
    int ans = sol.mincostTickets(d, c);
    cout<<ans;
    return 0;
}