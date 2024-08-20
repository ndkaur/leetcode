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
    int gridCnt = 0;
    int checkbfs(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>> visited(n, vector<int>(m,0));
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    cnt++;
                    q.push({i,j});
                    visited[i][j] = 1;

                    while(q.size()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        gridCnt++;

                        for(auto dir:dirs){
                            int nx = x + dir.first;
                            int ny = y + dir.second;
                            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1 && !visited[nx][ny]){
                                q.push({nx,ny});
                                visited[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
 
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       
        int cnt = checkbfs(grid);

        if(cnt==1 && gridCnt==1){
            return 1;
        }

        if(cnt>1 || cnt==0){ // more than one island or no island
            return 0;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int val = checkbfs(grid);
                    if(val>1){ // after changing ones more than 1 islands are made 
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2; // we need to change twice to make more than 1 islands 
    }
};

int main(){

    return 0;
}