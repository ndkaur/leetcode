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
    bool check(int i, int j, vector<vector<int>> & grid){
        if(i<0 || i>= grid.size() || j<0 || j>=grid[0].size() ||  grid[i][j]==0 || grid[i][j]==1)
            return false;
        return true;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n,3));
        // wall=0  guard=1   red=2   green =3

        for(int i=0;i<guards.size();i++)
            grid[guards[i][0]][guards[i][1]]=1;
        for(int i=0;i<walls.size();i++)
            grid[walls[i][0]][walls[i][1]]=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){ // guard

                    for(int left=j-1;left>=0;left--){
                        if(!check(i,left,grid)) // if wall or guard then cant go 
                            break;
                        grid[i][left] =2;
                    }

                    for(int right=j+1;right<n;right++){
                        if(!check(i,right,grid))
                            break;
                        grid[i][right]=2;
                    }

                    for(int up=i-1;up>=0;up--){
                        if(!check(up,j, grid))
                            break;
                        grid[up][j]=2;
                    }

                    for(int down=i+1;down<m; down++){
                        if(!check(down, j, grid))
                            break;
                        grid[down][j]=2;
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==3)
                    count++;
            }
        }
        return count;
    }
};


int main(){
    Solution sol;
    int m=4;
    int n=6;
    vector<vector<int>> guards={{0,0},{1,1},{2,3}};
    vector<vector<int>> walls={{0,1},{2,2},{1,4}};
    int ans= sol.countUnguarded(m,n,guards, walls);
    cout<<ans;
    return 0;
}