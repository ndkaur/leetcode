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
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // i-j +ve -> below diagonal -> decresong order->max heap
        // i-j -> -ve -> above diagonal -> incresing order-> min heap 
        // for each row store the values in map < int , pq>
        // elements on same diagonal have the same i-j value so making that a key
        map<int,priority_queue<int>> mx_heap;
        map<int, priority_queue<int, vector<int>, greater<int>>> mn_heap;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int key = i-j;
                if(key<0){ // -ve above diag  incr order ,mn heap
                    mn_heap[key].push(grid[i][j]);
                }
                else {
                    mx_heap[key].push(grid[i][j]);
                }
            }
        } 

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int key = i-j;
                if(key<0){
                    grid[i][j] = mn_heap[key].top();
                    mn_heap[key].pop();
                }
                else{
                    grid[i][j] = mx_heap[key].top();
                    mx_heap[key].pop();
                }
            }
        }
        return grid;
    }
};

int main(){

    return 0;
}