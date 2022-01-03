/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
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
// class Solution {
// public:
//     class node{
//         public:
//         string dest;
//         double wt;
//         node(string d, double w){
//             dest = d;
//             wt=w;
//         }
//     }
//     unordered_map<string, vector<node>> mp;
//     double dfs(string src, string des, set<string> visited){
//         if(!mp.count(src) || !mp.count(des)) return -1; //(x->y)
//         if(src==des) return 1; // (a->a)
//         visited.insert(src);
//         for(auto itr:mp[src]){
//             if(!visited.count(itr.des)){
//                 double ans = dfs(itr.dest,des,visited);
//                 if(!ans=-1) return ans * itr.wt;
//         }
//         return -1;
//     }
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         int nv=values.size();
//         int nq= queries.size();
//         for(int i=0;i<nv;i++){
//             auto u= equations[i][0];
//             auto v= equations[i][1];
//             mp[u].push_back({v,values[i]});
//             mp[v].push_back({u,1/values[i]});
//         }
//         vector<double> ans(nq);
//         set<string> visited;
//         for(int i=0;i<nq;i++){
//             ans[i]= dfs(queries[i][0],queries[i][1],visited);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    void dfs(string s, string d, map<string,vector<pair<string,double>>>& mp, set<string> visited, double& ans, double temp){
        if(visited.find(s)!=visited.end()) return ;
        else{
            visited.insert(s);
            if(s==d){
                ans= temp;
                return;
            }
            else {
                for(auto itr:mp[s]){
                    dfs(itr.first,d,mp,visited,ans,temp*itr.second );
                }
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>> mp;
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        vector<double> res;
        for(int i=0;i<queries.size();i++){
            string s= queries[i][0]; // start
            string d= queries[i][1]; // destination
            set<string> visited;
            double ans = -1.0;
            if(mp.find(s)!=mp.end()) // if start present
            dfs(s,d,mp,visited,ans, 1.0);
            res.push_back(ans);
        }
        return res;
    }
}; 

// @lc code=end


int main(){
    Solution sol;
    vector<vector<string>> equation = {{"a","b"},{"b","c"}};
    vector<double> values= {2.0,3,0};
    vector<vector<string>> queries={{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    vector<double> ans =sol.calcEquation(equation,values,queries);
    for(auto i:ans){
        cout<<i<<endl;
    }
   return 0;
}