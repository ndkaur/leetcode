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


// class DSU{
// public:
//     vector<int> parent;
//     DSU(int n){
//         parent.resize(n);
//         for(int i=0; i<n; i++){
//             parent[i]=i;
//         }
//     }

//     int find(int x){
//         if(parent[x]==x)
//             return x;
//         return parent[x] = find(parent[x]);
//     }

//     void unionn(int a,int b){
//         a = find(a);
//         b = find(b);
//         if(a==b)
//             return;
//         if(a!=b){
//             parent[b]=a;
//         }
//         return;
//     }
// };

// class Solution {
// public:
//     vector<bool> friendRequests(int n, vector<vector<int>>& rest, vector<vector<int>>& requ) {
//         int m = requ.size();
//         vector<bool> ans;

//         DSU dsu(n);

//         for(auto req:requ){
//             bool flag = true;
//             int parU = dsu.find(req[0]);
//             int parV = dsu.find(req[1]);

//             for(auto r:rest){
//                 int parResU = dsu.find(r[0]);
//                 int parResV = dsu.find(r[1]);
//                 // if restricted edge already connected 
//                 if((parU==parResU  && parV==parResV) || (parU==parResV && parV==parResU)){
//                     flag = false;
//                     break;
//                 }
//             }
//             ans.push_back(flag);
//             if(flag)
//                 dsu.unionn(parU, parV);
//         }
//         return ans;
//     }
// };


// for each request check if any restriced edge added , if not then return true and do union of request edges  

class Solution {
  vector<int> parents;
    int find_set(int v)
    {
        if(v == parents[v])
            return v;
        return parents[v] = find_set(parents[v]);
    }
    void union_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a == b)
            return;
        if(a != b)
            parents[b] = a;
        return;
    }
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        for(int i = 0; i < n; i++)
            parents.push_back(i);
        vector<bool> ans;
        for(vector<int> &req : requests){
            int v = 1;
            int a = find_set(req[0]);
            int b = find_set(req[1]);

            for(vector<int> &res : restrictions){
                int r1 = find_set(res[0]);
                int r2 = find_set(res[1]);
                if((a == r1 && b == r2) || (b == r1 && a == r2)){
                    v = 0;
                    break;
                }
            }
            ans.push_back(v);
            if(v){
                union_set(a,b);
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}