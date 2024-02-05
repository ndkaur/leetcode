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


// using flowyd warshall

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<long long>> dist(26, vector<long long>(26,INT_MAX));

        for(int i=0; i<n; i++){
            // original char -> changed char  with given weight 
            int o = original[i]-'a'; 
            int c = changed[i]-'a';
            dist[o][c]  = min(dist[o][c], (long long)cost[i]);
        }
        
        // using flowyd warshall 
        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        long long ans = 0;
        for(int i=0; i<source.size(); i++){
            if(source[i]==target[i])
                continue;
            int s = source[i]-'a';
            int t = target[i]-'a';
            if(dist[s][t]>=INT_MAX)
                return -1;
            ans += dist[s][t];
        }
        return ans;
    }
};



class Solution {
public:
    void bfs(char source, unordered_map<char,vector<pair<char,int>>>& adj, vector<vector<int>>& dist){
        queue<pair<int,int>> q;
        q.push({source, 0});

        while(q.size()){
            int node = q.front().first;
            int cost = q.front().second;
            q.pop();

            for(auto itr:adj[node]){ // prev cost + curr node cost < dist[curr node] 
                if(dist[source-'a'][itr.first-'a'] > cost + itr.second){
                    dist[source-'a'][itr.first-'a'] = cost + itr.second;
                    q.push({itr.first, cost+itr.second});
                }
            }
        }
        return;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // make a graph adj list
        int n = original.size();

        unordered_map<char,vector<pair<char,int>>> adj(26);

        for(int i=0; i<n; i++){
            adj[original[i]].push_back({changed[i],cost[i]});
        } 

        long long sum = 0;
        vector<vector<int>> dist(26, vector<int>(26,INT_MAX));

        // src -> abcd  , target -> acbe 
        //now fill the dist array 
        for(auto s:original){
            bfs(s, adj, dist);
        }

        for(int i=0; i<source.size(); i++){
            if(source[i]==target[i])
                continue;

            if(dist[source[i]-'a'][target[i]-'a']==INT_MAX)
                return -1;
            else 
                sum += dist[source[i]-'a'][target[i]-'a'];
        }
        return sum ;
    }
}; 


int main(){

    return 0;
}