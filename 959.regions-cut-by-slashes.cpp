/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
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

//O(N^2)
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int cnt;

    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unionn(int x, int y){
        int nx= find(x);
        int ny = find(y);
        if(nx!=ny){// different parents
            if(rank[nx]>rank[ny])
                parent[ny] = nx;
            else if(rank[nx]<rank[ny])
                parent[nx] = ny;
            else{
                parent[nx] = ny;
                rank[ny]++;
            }
        }
        else  // same parents increase cnt cause cycle formed 
            cnt++;
    }

    int regionsBySlashes(vector<string>& grid) {
        int sz= grid.size();
        int dots = sz+1;

        parent.resize(dots*dots);
        rank.resize(dots*dots);
        cnt =1;
         
        // initilazing
        for(int i=0; i<parent.size(); i++){
            parent[i]=i;
            rank[i]=1; 
        }
        
        // fill the boundary  i*n + j
        for(int i=0; i<dots; i++){
            for(int j=0; j<dots; j++){
                // combine all the boundary values  
                if(i==0 || j==0 || i==dots-1 || j==dots-1){
                    int cellno = i*dots +j;
                    if(cellno!=0)
                        unionn(0,cellno);
                } 
            }
        }
        
        for(int i=0; i<sz; i++){
            for(int j=0; j<sz; j++){
                if(grid[i][j]=='/'){
                    // i,j = (i,j+1) (i+1,j)
                    int x = i*dots+j+1;
                    int y = (i+1)*dots+j;
                    unionn(x,y);
                }
                else if(grid[i][j]=='\\'){
                    // i,j  = (i,j) (i+1,j+1)
                    int x = i*dots+j;
                    int y = (i+1)*dots+(j+1);
                    unionn(x,y);
                }
            }
        }
        return cnt;
    }
};

// union find 

class Solution {
public:
    vector<int> parent;
    
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // path compression  
    }

    int regionsBySlashes(vector<string>& grid) {
        vector<vector<int>> mat(grid.size()+1, vector<int>(grid.size()+1));
        int n = mat.size();
        parent.resize(n*n);

        // checking for the boundary values 
        // to find which region it is -> i*n + j 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0 || i==n-1 || j==n-1)
                    parent[i*n+j] = 0;
                else 
                    parent[i*n+j] = (i*n)+j;
            }
        }

        // for the graph make a matrix with 1 more size than actual
        // mark the slashes according to the indexex
        // front slash = (i,j) -> (i+1,j) & (i,j+1)
        // back slash  = (i,j) -> (i,j) & (i+1, j+1)
        int cnt =1 ; //already one whole region exist 
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid.size(); j++){
                // forward slash 
                if(grid[i][j] == '/'){
                    int par1 = find(i*n + (j+1)); // i, j+1
                    int par2 = find((i+1)*n + j); // i+1 , j
                    if(par1 == par2) // if both belong to same parent 
                        cnt++; 
                    else 
                        parent[par1] = par2; // union of parents into one 
                }
                // backward slash 
                else if(grid[i][j] == '\\'){
                    int par1 = find(i*n + j); // i,j
                    int par2 = find((i+1)*n + (j+1)); // i+1, j+1
                    if(par1 == par2)
                        cnt++;
                    else   
                        parent[par1] = par2;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end


int main(){

    return 0;
}