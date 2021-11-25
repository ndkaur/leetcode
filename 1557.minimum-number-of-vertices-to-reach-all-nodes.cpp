/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start
// count the nodes with incoming values =0
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> check(n,0);
        for(int i=0;i<edges.size();i++){
            check[edges[i][1]] =1;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(check[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};


// @lc code=end


int main(){
    Solution sol;
    int n=4;
    vector<vector<int>> edges={{1,2},{3,2},{1,3},{1,0},{0,2},{0,3}};
    vector<int> ans = sol.findSmallestSetOfVertices(n,edges);
    print(ans);
    return 0;
}