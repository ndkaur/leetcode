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

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int sz = edges.size();
        vector<int> indeg(n,0);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            indeg[v]++;
        }
        int cnt = 0;
        int val = -1;
        for(int i=0; i<indeg.size(); i++){
            if(indeg[i]==0){
                cnt++;
                val = i;
            }
        }
        if(cnt>1)
            return -1;
        else 
            return val;
    }
};  


int main(){

    return 0;
}