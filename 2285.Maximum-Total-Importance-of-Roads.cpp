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
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegre(n,0);
        long long ans=0;
        for(auto road:roads){
            indegre[road[0]]++;
            indegre[road[1]]++;
        }
        sort(indegre.begin(), indegre.end());
        // highest indegree= highest importance
        long long i=1;
        for(auto degre:indegre){
            ans+= degre*i;
            i++;
        }
        return ans;
    }
};

//  t->O(nlogn)
//  s->O(n)
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        //  calculate the indegree
        vector<int> indegree(n);
        for(auto &road:roads){
            indegree[road[0]]++;
            indegree[road[1]]++;
        }
        //  sort the indegree acc to highest first -> use pq
        // pq {ingderee, actual index of the nums}
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({indegree[i],i});
        }
        //  to assign the values to each node acc to the degree
        // pq top val is the max val 
        vector<int> values(n);
        int importance=n;
        while(!pq.empty()){
            int top= pq.top().second; // {4,3}
            // highest indegree nd=ode gets the highest importance 
            values[top]= importance;
            importance--;
            pq.pop();
        }
        long long sum=0;
        for(auto &road:roads){
            sum+= (values[road[0]] + values[road[1]]);
        }
        return sum;
    }
};


int main(){
    Solution sol;
    int n=5;
    vector<vector<int>> roads= {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    int ans= sol.maximumImportance(n,roads);
    cout<<ans;
    return 0;
}