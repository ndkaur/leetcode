/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
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

// time  o(n^2)
// space O(n)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        // make an adj list 
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)
                    continue;
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1]- points[j][1]);
                adj[i].push_back({j, weight});
                adj[j].push_back({i,weight});
            }
        }
        vector<int> key(n);
        vector<int> parent(n); // we actually dont need parent int this 
        vector<bool> mst(n);
        // initilazing
        for(int i=0; i<n; i++){
            key[i] =INT_MAX;
            parent[i] = -1;
            mst[i]= false;
        }
        // for the source 
        key[0]=0;
        parent[0] =0;

        for(int i=0; i<n-1; i++){
            // finding the min val in key 
            int mn= INT_MAX;
            int u; // to store the index of min val node 
            for(int v=0; v<n; v++){
                if(mst[v]== false && key[v] < mn){
                    mn= key[v];
                    u=v;
                }
            }
            // mark mst 
            mst[u] = true;
            // visit all the adj nodes
            for(auto itr: adj[u]){
                int val = itr.first;
                int wght= itr.second;
                // if lesser weight found then keep it 
                if(mst[val] == false && wght< key[val]){
                    parent[val] = u;
                    key[val] = wght;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+= key[i];
        }
        return ans;
    }
};


// O(nlogn)
//O(n)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)
                    continue;
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1]- points[j][1]);
                adj[i].push_back({j, weight});
                adj[j].push_back({i,weight});
            }
        }
        vector<int> key(n,INT_MAX);
        vector<bool> mst(n,false);
    
        // priority queue // min dist , idx 
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        // for the source 
        key[0]=0;
        pq.push({0,0});

        while(!pq.empty()){
            int u= pq.top().second; // min weight 
            pq.pop();
            // mark mst
            mst[u] = true;
            // visiting all the adj of u 
            for(auto itr:adj[u]){
                int val = itr.first;
                int wght= itr.second;
                if(mst[val] == false && wght < key[val]){
                    key[val] = wght;
                    pq.push({key[val], val}); // weight, node
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+= key[i];
        }
        return ans;
    }
};

// dsu 
// Time complexity:O(E)
// Space complexity:O(E)

class Solution {
public:
    vector<int> parent;

    int find(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void un(int u, int v){
        u = find(u);
        v = find(v);
        if(u==v)
            return;
        parent[u] = parent[v];
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        // making an arr to store all distance of one point wrt other points 
        vector<pair<int,pair<int,int>>> arr; // {dist,{i,j}}
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                arr.push_back({abs(points[i][0]- points[j][0])+ abs(points[i][1]-points[j][1]), {i,j}});
            }
        }
          
        sort(arr.begin(), arr.end());
        int ans =0;

        for(auto itr: arr){
            int par1 = find(itr.second.first); // parent of i 
            int par2 = find(itr.second.second); // parent of j 
            if(par1 != par2){ // if both parents different perform union 
                ans += itr.first; // add the distance 
                un(par1,par2);
            }
        }
        return ans;
    }
};







// @lc code=end


int main(){

    return 0;
}