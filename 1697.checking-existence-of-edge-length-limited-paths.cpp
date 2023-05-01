/*
 * @lc app=leetcode id=1697 lang=cpp
 *
 * [1697] Checking Existence of Edge Length Limited Paths
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

class DSU {
    public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        return parent[x] = parent[x] == x ? x : find(parent[x]);
    }
    bool unionn(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset != yset) {
            rank[xset] < rank[yset] ? parent[xset] = yset : parent[yset] = xset;
            rank[xset] += rank[xset] == rank[yset];
            return true;
        }
        return false;
    }
};


class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        // creating object for dsu class
        DSU dsu(n);

        // sort the queries on basis of limit distance but 
        // the order in which queries given must remain the same so add idx to it first 
        for(int i=0; i<queries.size(); i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [&](auto const &a, auto const &b){
            return a[2]<b[2];
        });

        // sort the edges int increasing order on the basis of distance
        sort(edges.begin(), edges.end(), [&](auto const &a, auto const &b){
            return a[2]<b[2];
        });

        // if the query is in the dsu tree after return true otherwise false
        int i=0; 
        vector<bool> ans(queries.size(), false);

        for(auto q:queries){
            // for each query check all edges
            while(i<edges.size() && edges[i][2] < q[2]){
                dsu.unionn(edges[i][0], edges[i][1]);
                i++;
            }
            //both the dges start to end edge will be in the same treeif the conditoin of smaller is passed
            if(dsu.find(q[0]) == dsu.find(q[1])){
                ans[q[3]] = true;
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}