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
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        vector<vector<int>> visited(n,vector<int>(m,false));

        vector<vector<int>> dirs = {{1,0},{0,1},{0,-1},{-1,0}};

        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});

        while(pq.size()){
            auto t = pq.top();
            pq.pop();

            int time = t[0];
            int i = t[1];
            int j = t[2];
            // if reached the last cell
            if(i == n-1 && j==m-1)
                return time;
            // already visited 
            if(visited[i][j] == true)
                continue;

            visited[i][j] = true;

            for(auto dir:dirs){
                int row = i+dir[0];
                int col = j+dir[1];

                if(row<0 || row >=n || col<0 || col>=m || visited[row][col]) // negating conditions
                    continue; 
                // time to wait  = target next cell time - current time 
                // curr cell = 1 , next cell =3 , time = 1 so 
                // go to next cell t =2 , come back t= 3 , go again t= 4 so ultimate time with given condition stistfy = 4 
                bool wait = (grid[row][col] - time) % 2 == 0; // time needed above to visit that cell
                // if we moving directly to next cell as target cell then add prev time +1
                // or
                //  we can come back go again and repeat till its the time doesnt get according to condition 
                int newTime = max(grid[row][col] + wait , time +1);
                pq.push({newTime, row, col}); 
            }
        }
        return -1;
    }
};
// remaining time needed to reach = grid cell time - curr time 2
// if rem time % 2 ==0 then add 1 or add 0 

int main(){

    return 0;
}