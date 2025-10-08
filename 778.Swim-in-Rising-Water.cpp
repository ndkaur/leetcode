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


class Solution { // O(n^2 log(n^2)) // bfs = n^2 , binary search  = logn 
public:
    bool isPossible(int time, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

        vector<vector<bool>> visited(n,vector<bool>(m,0));
        queue<pair<int,int>> q;

        q.push({0,0});
        visited[0][0]=1;

        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto x = q.front().first;
                auto y = q.front().second;
                q.pop();

                if(x==n-1 && y==m-1)
                    return true;
                
                for(auto dir:dirs){
                    int nx = x+dir.first;
                    int ny = y+dir.second;
                    if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && 
                        grid[nx][ny]<=time){
                            q.push({nx,ny});
                            visited[nx][ny]=1;
                    }
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // we want to find the min max time where all the boxes around it have value min that it -> gives idea of binary search , then ispossible function we will try on grid using bfs 
        int l = grid[0][0];
        int h = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                h = max(h, grid[i][j]);
            }
        }

        int ans = h;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(isPossible(mid, grid)){
                ans = mid;
                h = mid-1;
            }
            else 
                l = mid+1;
        }

        return ans;
    }
};



int main(){

    return 0;
}