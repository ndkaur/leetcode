/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
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
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> visited = grid;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] == 1)
                    q.push({i,j});
            }
        }

        if(q.size()==0 || q.size() == n*n)
            return -1;
        
        int ans = -1;
        
        vector<pair<int,int>> dirs ={{0,1},{1,0}, {0,-1},{-1,0}};
        
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto t= q.front();
                q.pop();
                int x = t.first;
                int y = t.second;
                for(auto dir:dirs){
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    if(nx>=0 && nx<n && ny>=0 && ny<m  && visited[nx][ny]==0){
                        visited[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}