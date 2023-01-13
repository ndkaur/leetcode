/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 */
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
// @lc code=start


class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0,-1,adj, hasApple); // curr, prev
    }
    int dfs(int curr, int prev, vector<vector<int>>& adj, vector<bool>& hasApple){
            int ans = 0;
            for(auto itr:adj[curr]){
                // 0 -> 1  and 1->0 so it deosnt repeat that why check if itr and prev arnt same 
                if(itr != prev){
                    int res = dfs(itr, curr, adj, hasApple);
                    if(res > 0 || hasApple[itr]){ // if child nodes doent have apple so res is 0 or has apple 
                        ans += res+2; // come and go back so 2 
                    }
                }
            }
            return ans;
    }
};

// 0 -> 1, 2
// 1 -> 0, 4 , 5
// 2 -> 0 , 3 , 6
// 3 -> 2
// 4 -> 1
// 5 -> 1
// 6 -> 2 


// @lc code=end



int main(){

    return 0;
}