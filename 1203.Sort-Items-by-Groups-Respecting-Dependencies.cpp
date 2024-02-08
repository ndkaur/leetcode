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



// we want topological order of nodes such that rule 2 they occur according to before array 
// but the answer from this will not be correct cause we ant the same group elemts to occur together 
// so apply rule 1 also 
//  those with group -1 give them new group 
// step1-> apply rule 2 and make a topo array using before 
// step 2 -> make another graph on the basis of groups and apply topo on it 
// step3 -> use the group topo to put elemts in order in the before topo 

class Solution {
public:
    vector<int> topoSort(unordered_map<int, vector<int>>& adj, vector<int>& indeg){
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<indeg.size(); i++){
            if(indeg[i]==0)
                q.push(i);
        }

        while(q.size()){
            auto node= q.front();
            q.pop();
            ans.push_back(node);

            for(auto itr:adj[node]){
                indeg[itr]--;
                if(indeg[itr]==0){
                    q.push(itr);
                }
            }
        }
        return ans.size()==adj.size() ? ans : vector<int>();
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // giving group to -1 
        for(int i=0; i<n; i++){
            if(group[i]==-1){
                group[i]= m++;
            }
        }

        // topo for before array 
        unordered_map<int,vector<int>> beforeGraph;
        vector<int> beforeIndeg(n,0);

        // topto for group array 
        // groupGraph the node values must be groups values 
        //  so make edges between the groups 
        // we know that what node belongs to what group 
        // but we dont know which group will have directed edge pointing to which node 
        // so we use the before node to find that 
        // each group -> can come before many other groups so vectorint 
        unordered_map<int,vector<int>> groupGraph;
        vector<int> groupIndeg(m,0);

        // filling both 
        for(int i=0; i<n; i++){
            // i, before , before->i
            for(int b:beforeItems[i]){
                beforeGraph[b].push_back(i);
                beforeIndeg[i]++;

                // if the node before->i has same group no need but if diff then make edge in groupGraph
                if(group[b]!=group[i]){
                    groupGraph[group[b]].push_back(group[i]);
                    groupIndeg[group[i]]++;
                }
            }
        }

        // now call topo seperately for both graphs 
        vector<int> beforeTopo = topoSort(beforeGraph, beforeIndeg);
        vector<int> groupTopo = topoSort(groupGraph, groupIndeg);

        if(beforeTopo.empty() || groupTopo.empty())
            return {};

        // rule 2 -> order of before must be followeed
        // so we take nodes out in order of beforeTop and put each node against group to which it belongs 
        // eg -> group =0 -> {6,3,5} 
        //    -> group = 1 -> {2,1}
        //    -> group 3 -> {7,4}  
        // now for each group we need to add its vector in order of rule 1 
        // rule 1 -> same groups node must occur together 
        //  so go in groupTopo and fro each group call map and add its vector into ans

        unordered_map<int,vector<int>> mp; // group -> { nodes in beforeTopo order}
        
        for(int node:beforeTopo){
            // find node against that group 
            //because the groupTopo will give order of only the groups 
            // so pick the group in that order and push them to nodes int the before order 
            int findGroup =  group[node];
            mp[findGroup].push_back(node); 
        }

        // now according to groupTopo order add values from mp to ans
        vector<int> ans;
        for(int g:groupTopo){
            vector<int> temp = mp[g];
            for(int i=0; i<temp.size(); i++){
                ans.push_back(temp[i]);
            }
        }
        
        return ans;
    }
}; 

// eg:- 
// n = 8, m = 2, 
// group = [-1,-1,1,0,0,1,0,-1], 
// beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]


// rename groups -1 as m++ , m =5
//  0 1 2 3 4 5 6 7
//  2 3 1 0 0 1 0 4  

// beforeGraph  adj map
// 0->{} ,  1->{},  2->{},  3->{4},  4->{},  5->{2},  6->{1,3,4},   7->{} 
// beforeIndeg 
//  0 1 2 3 4 5 6 7
//  0 1 1 1 2 0 0 0 

//  beforeTopo order =>   {0,5,6,7,2,1,3,4}


// group graph -> to make group graph compare the nodes  before->i then group of before-> group of i 
// eg-> 3->4 , group of 3 = 0 -> group of 4 = 0 , same group then no edge  
//  eg -> 6->1, group of 6=0 -> group of 1 =3, 0->3 edge in group graph 

// groupGraph adj map
// 0 ->{3}, 1->{}, 2->{}, 3->{}, 4->{}
// groupIndeg 
//  0 1 2 3 4
//  0 0 0 1 0 

// groupTopo
// {0 1 2 4 3}

// rule 1 -> same group occur together 
//  rule 2 -> before eorder must me maintained 

// so to maintain before order 
// beforeTopo order =>   {0,5,6,7,2,1,3,4}

// take each ele from beforeorder topo and add it next to its group number 
// make a map for each {group, vector<int>{nodes  belonging to that group in topoBefore order}}
// mp group  nodes
//     0     {6,3,4}
//     1     {5,2}
//     2     {0}
//     3     {1}
//     4     {7}

// now traverse for completing rule 1 , same group occur together

// groupTopo
// {0 1 2 4 3}
// go on each elem of groupTopo and add the nodes stored in map against it 
//  ans= {6,3,4, 5,2, 0, 7, 1}



int main(){

    return 0;
}