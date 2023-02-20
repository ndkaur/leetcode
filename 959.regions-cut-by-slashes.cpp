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