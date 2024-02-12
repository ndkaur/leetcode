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


class Solution { //(O(V+E)logN)
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{-1,0},{1,0}};

        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        dist[0][0] = 0;

        // sum, i, j, 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});

        while(pq.size()){
            auto val = pq.top();
            pq.pop();

            int sum = val.first;
            int i = val.second.first;
            int j = val.second.second;

            for(auto dir:dirs){
                int ni = i + dir.first;
                int nj = j + dir.second;
                if(ni<0 || ni>=n || nj<0 || nj>=m)
                    continue;
                
                int temp;
                if(grid[ni][nj]==1){
                    temp=1;
                }
                else{
                    temp=0;
                }
                // prevWt + curWt < dist[curr]
                if(sum + temp < dist[ni][nj]){
                    dist[ni][nj] = sum + temp;
                    pq.push({dist[ni][nj],{ni, nj}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};


int main(){

    return 0;
}