#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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

class Solution {
public:
    unordered_map<int,unordered_set<int>> out,in;
    int ans=0;

    void dfs(int node){
        for(int x:out[node]){
            ans++;
            in[x].erase(node);
            dfs(x);
        }
        for(int x:in[node]){
            out[x].erase(node);
            dfs(x);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        ans=0;
        for(auto x:connections){
            out[x[0]].insert(x[1]);
            in[x[1]].insert(x[0]);
        }
        dfs(0);
        return ans; 
    }
};


int main(){
    
    return 0;
}