/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
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

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int node){
        if(parent[node]==node)
            return node;
        return parent[node]= find(parent[node]);
    }
    
    void unionn(int x, int y){
        if(rank[x]<rank[y])
            parent[x]=y;
        else if(rank[y]<rank[x])
            parent[y]=x;
        else{
            parent[x]=y;
            rank[y]++;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        int sz=27;
        parent.resize(sz);
        rank.resize(sz);
        for(int i=0;i<27;i++){
            parent[i]=i;
            rank[i]=0;
        }
        // a==b  1234
        for(auto equ:equations){
            int a = find(equ[0]-'a');
            int b = find(equ[3]-'a');
            if(equ[1]=='=')
                unionn(a,b);
        }
        
        for(auto equ:equations){
            int a = find(equ[0]-'a');
            int b = find(equ[3]-'a');
            if(equ[1]=='!'){
                // if ! then if belong to same parent then it should be false
                if(a==b)
                    return false;
            }
        }
        return true;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<string> equations={"a==b","b!=a"};
    bool ans= sol.equationsPossible(equations);
    cout<<ans;
   return 0;
}