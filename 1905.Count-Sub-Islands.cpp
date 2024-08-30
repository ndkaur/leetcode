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
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        int cnt = 0;
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j]==0 || visited[i][j]==1){
                    continue;
                }
                queue<pair<int,int>> q;
                q.push({i,j});
                bool flag = true;
                visited[i][j] = true;

                while(q.size()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    if(grid1[x][y]==0)
                        flag = false;
                    
                    for(auto dir:dirs){
                        int nx = x+dir.first;
                        int ny = y+dir.second;
                        
                        if(nx>=0 && nx<n && ny>=0 && ny<m && grid2[nx][ny]==1 && !visited[nx][ny]){
                            visited[nx][ny]=true;
                            q.push({nx,ny});
                        }
                    }
                }
                if(flag)
                    cnt++;
            }
        }
        return cnt;
    }
}; 



int main(){

    return 0;
}