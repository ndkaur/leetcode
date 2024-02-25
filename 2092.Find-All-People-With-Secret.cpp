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
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto meet:meetings){
            int u = meet[0];
            int v = meet[1];
            int t = meet[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0}); // time , node
        pq.push({0, firstPerson});

        vector<int> visited(n,0);
        while(pq.size()){
            auto time = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            if(visited[node])
                continue;
            visited[node] = 1;
            for(auto itr:adj[node]){
                int child = itr.first;
                int childTime = itr.second;
                if(visited[child])
                    continue;
                // parent must be visited first so its time is more , and child time less then only secret can be shared 
                if(childTime >= time){
                    pq.push({childTime, child});
                }
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(visited[i])
                ans.push_back(i);
        }
        return ans;
    }
};


int main(){

    return 0;
}