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
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<priority_queue<int>> pq(n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pq[i].push(grid[i][j]);
            }
        }
        int sum =0;
        // for each col visite each elem of row 
        for(int j=0; j<m; j++){
            int temp =0;
            for(int i=0; i<n; i++){
                temp = max(temp, pq[i].top());
                pq[i].pop();
            }
            sum += temp;
        }
        return sum;
    }
};

int main(){

    return 0;
}