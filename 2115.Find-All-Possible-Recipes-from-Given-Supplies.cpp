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

class Solution {
public:
      map<string,vector<string>> graph;        
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
      int n= recipes.size();
      graph.clear();
      map<string,int> indegree;

      for(int i=0;i<ingredients.size();i++){
            for(string s:ingredients[i]){
                  graph[s].push_back(recipes[i]);
                  indegree[recipes[i]]++;
            }
      }

      queue<string> q;
      for(string item:supplies){
            if(indegree[item]==0)
                  q.push(item);
      }
      while(!q.empty()){
            string node= q.front();
            q.pop();
            for(string it:graph[node]){
                  indegree[it]--;
                  if(indegree[it]==0)
                        q.push(it);
            }
      }

      vector<string> ans;
      for(string rec:recipes){
            if(indegree[rec]==0)
                  ans.push_back(rec);
      }
      return ans;
    }
};

int main(){
      Solution sol;
      vector<string> recipes={"bread"};
      vector<vector<string>> ingredients ={"yeast","flour"};
      vector<string> supplies={"yeast","flour","corn"};
      vector<string> ans =sol.findAllRecipes(recipes,ingredients,supplies);
      for(int i=0;i<ans.size();i++){
            cout<<ans[i];
      }
   return 0;
}