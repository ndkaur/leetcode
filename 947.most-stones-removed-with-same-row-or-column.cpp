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

// we find the count of how many times a node get visited more than ones 
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();
        vector<bool> visited(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            // to find cnt of how many times visited after visitong ones
            if(visited[i])
                continue;
            cnt+=dfs(stones, visited ,i,n);
        }
        return cnt;
    }
    int dfs(vector<vector<int>>& stones, vector<bool>& visited, int source, int& n){
        visited[source]=true;
        int count=0;
        for(int i=0;i<n;i++){
            // if our previous node and the current node values are equal 
            if(!visited[i] && (stones[i][0]==stones[source][0] || stones[i][1]== stones[source][1])){
                count += (dfs(stones, visited, i,n) +1);
            }
        }
        return count;
    }
};


//  union find 
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x==parent[x])
            return x;
        return parent[x]= find(parent[x]);
    }

    void unionf(int u, int v){
        u= find(u);
        v= find(v);
        if(rank[u]<rank[v])
            parent[u]=v;
        else if(rank[v]<rank[u])
            parent[v]= u;
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // when equal then only we can put in same group 
                if(stones[i][0]== stones[j][0] || stones[i][1] == stones[j][1]){
                    // both lie in same component so attach them together 
                    unionf(i,j);
                }
                // combinig the nodes with the same parent 
            }
        }
        // to find the no of conencted components ie no of groups formed
        int cnt=0;

        for(int i=0;i<n;i++){
            // parent i and i equal means belong to same group 
            // i=0  p[0]=0  (0 == 0)  cnt=1
            //i=1 p[1] = 1  (1 == 1) cnt=2
            // i=2  p[2]=0  (0!=2)
            if(parent[i]==i)
                cnt++;
        }
        // moves count= stones total count - groups connected(conected comp)
        return n-cnt;
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



// {{0,0},{0,2},{1,1},{2,0},{2,2}}

// group1      group2 
//  {0,0}         {1,1}
//  {0,2}
//  {2,0}
//  {2,2}

// so 2 groups formed then ans will be total len- groups formed




