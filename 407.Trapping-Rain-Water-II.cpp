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
    #define pip pair<int,pair<int,int>>
    bool isValid(int& x, int& y, int& n , int& m){
        return (x>=0 && x<n && y>=0 && y<m);
    }
    int trapRainWater(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        // if size less than 3 no boundary can be formed
        if(n<3 && m<3)
            return 0;
        
        priority_queue<pip, vector<pip>, greater<pip>> pq;

        vector<vector<bool>> visited(n, vector<bool>(m,false));

        // filling pq with the boundar values
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // startin from the boundary values 
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    pq.push({heights[i][j], {i,j}});
                    visited[i][j] = true;
                }
            }
        }

        // doing the bfs
        int level = 0;
        int traped_water = 0;
        // URDL
        vector<pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};

        while(!pq.empty()){
            pip curr = pq.top();
            pq.pop();

            int h = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            level = max(level, h); // keep on updating the max height for the curr box according to its 
            // its surrounding 4 directions

            for(auto dir:dirs){
                int nx = x + dir.first;
                int ny = y + dir.second;

                if(isValid(nx,ny, n, m) && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    pq.push({heights[nx][ny],{nx, ny}});
                    
                    if(heights[nx][ny] < level){
                        traped_water += level-heights[nx][ny];
                    }
                }
            }
        }
        return traped_water;
    }
};


int main(){

    return 0;
}