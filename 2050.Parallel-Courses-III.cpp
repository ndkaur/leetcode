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

class Solution0 {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1);
        for(auto r:relations){
            adj[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }
        queue<int> q;

        for(int i=1;i<=n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> dp(n+1);
        while(!q.empty()){
            int node= q.front();
            q.pop();
            dp[node] += time[node-1];
            for(auto itr:adj[node]){
                if(!--indegree[itr]){
                    q.push(itr);
                }
                dp[itr] = max(dp[itr],dp[node]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        vector<int> ctime(n,0);

        for(auto &r:relations){
            adj[r[0]-1].push_back(r[1]-1);
            indegree[r[1]-1]++;
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(!indegree[i])
                q.push({i,0});
        }
        while(!q.empty()){
            int node= q.front().first;
            int t= q.front().second;
            q.pop();

            int completeTime = t+time[node];
            ctime[node] = completeTime;

            for(int &itr:adj[node]){
                ctime[itr]= max(ctime[itr],completeTime);
                if(!--indegree[itr])
                    q.push({itr,ctime[itr]});
            }
        }
        return *max_element(ctime.begin(),ctime.end());
    }       
}; 

// we do topo sort , gives the order of what comes after what
// then if 1->3 = t1  , 2->3 =t2  
// max time of the node and the adj node , fill the ctime array 
//  main motive is to get the max time  from max of ctime array 

int main(){
    Solution sol;
    int n =3;
    vector<vector<int>> relations={{1,3},{2,3}};
    vector<int> time={3,2,5};
    int ans = sol.minimumTime(n,relations,time);
    cout<<ans;
   return 0;
}