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
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        // pq -> {cost, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0,0,0});

        vector<vector<int>> visited(n, vector<int>(m,0));

        while(pq.size()){
            auto node = pq.top();
            pq.pop();
            int cost = node[0];
            int x = node[1];
            int y = node[2];
            
            if(visited[x][y])
                continue;

            visited[x][y] = 1;

            if(x==n-1 && y==m-1)
                return cost;

            for(int i=0; i<4; i++){
                int nx = x + dirs[i].first;
                int ny = y + dirs[i].second;
                if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny]){
                    // now after adding new direction the reslting dir is same as given in grid
                    // i+1 -> 0 based indexing , so right =1, left =2, up , down , 3,4
                    // new dir idx +1 == prev value of direction in grid 
                    if(i+1==grid[x][y]){
                        pq.push({cost, nx, ny});
                    }
                    else {
                        pq.push({cost+1, nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};


class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        vector<vector<int>> dp(n, vector<int>(m,INT_MAX));
        dp[0][0]=0;

        // pq -> {cost, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0,0,0});

        
        while(pq.size()){
            auto node = pq.top();
            pq.pop();
            int cost = node[0];
            int x = node[1];
            int y = node[2];
            

            if(x==n-1 && y==m-1)
                return cost;

            for(int i=0; i<4; i++){
                int nx = x + dirs[i].first;
                int ny = y + dirs[i].second;
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    // now after adding new direction the reslting dir is same as given in grid
                    // i+1 -> 0 based indexing , so right =1, left =2, up , down , 3,4
                    // new dir idx +1 == prev value of direction in grid 
                    int ncost = cost + (i+1!=grid[x][y]);
                    
                    if(ncost < dp[nx][ny]){
                        dp[nx][ny] = ncost;
                        pq.push({ncost, nx, ny});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};


class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        // pq -> {cost, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0,0,0});

        vector<vector<int>> visited(n, vector<int>(m,0));
        vector<vector<int>> dp(n, vector<int>(m,INT_MAX));
        dp[0][0]=0;

        while(pq.size()){
            auto node = pq.top();
            pq.pop();
            int cost = node[0];
            int x = node[1];
            int y = node[2];
            
            if(visited[x][y])
                continue;

            visited[x][y] = 1;

            if(x==n-1 && y==m-1)
                return cost;

            for(int i=0; i<4; i++){
                int nx = x + dirs[i].first;
                int ny = y + dirs[i].second;
                if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny]){
                    // now after adding new direction the reslting dir is same as given in grid
                    // i+1 -> 0 based indexing , so right =1, left =2, up , down , 3,4
                    // new dir idx +1 == prev value of direction in grid 
                    if(i+1==grid[x][y]){ 
                        if(cost<=dp[nx][ny]){
                            dp[nx][ny]=cost;
                            pq.push({cost, nx, ny});
                        }
                    }
                    else { // diff direction in grid 
                        if(cost+1<=dp[nx][ny]){
                            dp[nx][ny]= cost+1;
                            pq.push({cost+1, nx, ny});
                        }
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};

int main(){

    return 0;
}