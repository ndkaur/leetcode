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
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        unordered_set<string> ans;

        vector<pair<int,int>> dirs ={{0,1},{1,0},{-1,0},{0,-1}};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    string temp;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(q.size()){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        for(auto dir:dirs){
                            int nrow = row + dir.first;
                            int ncol = col + dir.second;
                            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                                grid[nrow][ncol] = 0; // marking visited
                                q.push({nrow,ncol});
                                temp += to_string(nrow-i) + to_string(ncol-j);
                            }
                        }
                    }
                    ans.insert(temp);
                }
            }
        }
        return ans.size();
    }
};



class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        unordered_set<string> islands;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    string island;
                    distinct(grid, i, j, i, j, island);
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
private:
    void distinct(vector<vector<int>>& grid, int i, int j, int r, int c, string& island) {
        int m = grid.size(), n = grid[0].size();
        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c]) {
            grid[r][c] = 0;
            island += to_string(r - i) + to_string(c - j);
            distinct(grid, i, j, r - 1, c, island);
            distinct(grid, i, j, r + 1, c, island);
            distinct(grid, i, j, r, c - 1, island);
            distinct(grid, i, j, r, c + 1, island);
        }
    }
};



int main(){

    return 0;
}