/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
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
class Solution0 {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();
        int count=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i])
                dfs(stones, visited, count , i);
        }
        return count ;
    }
    void dfs(vector<vector<int>>& stones, vector<bool>& visited , int& count, int node){
        visited[node]=true;
        vector<int> store= stones[node];
        for(int i=0;i<stones.size();i++){
            if(!visited[i] && (store[0]==stones[i][0] || store[1]== stones[i][1])){
                count++;
                dfs(stones,visited,count, i);
            }
        }
    }
};


class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        rank.resize(n,1);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                    unionn(i,j);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i)
                count++;
        }
        return n-count ;
    }
    int findParent(int x){
        if(x==parent[x]) return x;
        return parent[x]=findParent(parent[x]);
    }
    void unionn(int a, int b){
        int x= findParent(a);
        int y= findParent(b);
        if(rank[x]<rank[y])
            parent[x]=y;
        else if (rank[x]>rank[y])
            parent[y]=x;
        else {
            parent[x]=y;
            rank[y]++;
        }
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> stones ={{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    int ans = sol.removeStones(stones);
    cout<<ans;
   return 0;
}