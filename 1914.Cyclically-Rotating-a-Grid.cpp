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
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        // store all vals first in the required anti clockwise order for each layer 
        int layers = min(n,m)/2;

        for(int layer=0; layer<layers; layer++){
            vector<int> vals;
            // i->0->n-1 , j=0->m-1
            int top = layer; 
            int left = layer; 
            int bottom = n-layer-1;
            int right = m-layer-1;

            // filling the values 
            // top row -> clom change 
            for(int j=left; j<=right; j++){
                vals.push_back(grid[top][j]);
            }

            // right col -> i chnage
            for(int i=top+1; i<=bottom-1; i++){
                vals.push_back(grid[i][right]);
            }

            // bottom row -> j change , reverse order 
            for(int j=right; j>=left; j--){
                vals.push_back(grid[bottom][j]);
            }

            // left column-> i chanhe
            for(int i=bottom-1; i>=top+1; i--){
                vals.push_back(grid[i][left]);
            }

            // after filling the vals array , we need to again add in matrix according to the rotation 
            int sz = vals.size();
            int start = k%sz;
            int idx = start;

            // top row
            for(int j=left; j<= right; j++){
                grid[top][j] = vals[idx];
                idx++;
                if(idx==sz){
                    idx=0;
                }
            }

            // right colm 
            for(int i=top+1; i<=bottom-1; i++){
                grid[i][right] = vals[idx];
                idx++;
                if(idx==sz){
                    idx=0;
                }
            }

            // bottom row -> reverse order
            for(int j=right; j>=left; j--){
                grid[bottom][j] = vals[idx];
                idx++;
                if(idx==sz){
                    idx=0;
                }
            }

            // left colum -> revrse
            for(int i=bottom-1; i>=top+1; i--){
                grid[i][left] = vals[idx];
                idx++;
                if(idx==sz){
                    idx=0;
                }
            }
        }
        return grid;
    }
};


int main(){

    return 0;
}