/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
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
class Solution { // khans algo
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& qu) {
        vector<vector<int>> adj(num);
        vector<bool> ans;
        vector<int> indegree(num,0);
        vector<vector<bool>> check(num,vector<bool>(num,false));
        for(auto p:pre){
            int course= p[0];
            int depend= p[1];
            adj[course].push_back(depend);
            indegree[depend]++;
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int curr= q.front();
            q.pop();
            for(auto it:adj[curr]){ // curr=1 , itr is its adj =0 , mark[1,0]as true 
                check[curr][it]= true;
                for(int i=0;i<num;i++){
                    if(check[i][curr]==true) // check[0][1]
                        check[i][it]= true; // check[0][0]
                }
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        } 
        // check if the querie is marked true in table bool 
        for(int i=0;i<qu.size();i++){
            ans.push_back(check[qu[i][0]][qu[i][1]]);
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int num=2;
    vector<vector<int>> pre={{1,0}};
    vector<vector<int>> qu={{0,1},{1,0}};
    vector<bool> ans = sol.checkIfPrerequisite(num,pre,qu);
    for(auto i:ans){
        cout<<i<<endl;
    }
   return 0;
}