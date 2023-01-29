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
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int  n = edges.size();
        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);
        find(edges, node1, dist1);
        find(edges, node2, dist2);
        int mnDist = INT_MAX;
        int mnNode = -1;
        // both dist arrays , find the minimum max dist 
        for(int i =0; i<n; i++){
            if(dist1[i] != -1 && dist2[i] != -1){
                int mxDist = max(dist1[i], dist2[i]);
                if(mxDist < mnDist){
                    mnDist = mxDist;
                    mnNode = i; // we want the node with that dist 
                }
            }
        }
        return mnNode;
    }

    void find(vector<int>& edges, int source, vector<int>& dist){
        dist[source] = 0;
        queue<int> q;
        q.push(source);
        while(q.size()){
            int curr = q.front();
            q.pop();
            if(edges[curr] != -1){
                if(dist[edges[curr]] == -1){
                    dist[edges[curr]] = dist[curr]+1; // parent to child + 1
                    q.push(edges[curr]);
                }
            }
        }
    }
};



int main(){

    return 0;
}