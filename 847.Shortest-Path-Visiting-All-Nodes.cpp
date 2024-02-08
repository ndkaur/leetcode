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


// in simple bfs we visit a node and mark it visited, but in this question it is said that we can
//  revist the node and reuse it 
// so need to use bfs but with some new things 
// so we will use bitmask to stroe the visited state 
// node , bit mask of all visited  and store them in set
//  set visited { node, mask }
// the visited node mark as 1 in bit 
// start bfs from each node , put all in queue in begining 
// when mask becomes 1111 that means all visited and bfs automatically always gives shortest path 


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==1 || n==0)
            return 0;
        
        queue<pair<int,int>> q;
        set<pair<int,int>> st;

        for(int i=0; i<n; i++){
            int mask = (1<<i);
            q.push({i, mask});
            st.insert({i,mask});
        }

        //  1111 = 2^n -1
        int allVisited = (1<<n)-1;

        int path  = 0;
        while(q.size()){
            int sz = q.size();
            path++;
            while(sz--){
                auto node = q.front().first;
                auto maskVal = q.front().second;
                q.pop();

                for(auto itr:graph[node]){
                    // new mask = 1 << val of itr node then do OR with prev mask val to combine result 
                    int nxtMask = maskVal | (1<<itr);
                    if(nxtMask==allVisited)
                        return path;
                    
                    // check if not already visited
                    if(st.find({itr,nxtMask})==st.end()){
                        st.insert({itr, nxtMask});
                        q.push({itr, nxtMask});
                    }
                }
            }
        }
        return -1;
    }
};

int main(){

    return 0;
}