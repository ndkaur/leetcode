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
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> ans;
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j=0; j<m; j++){
                // take even cols
                if((i+j)%2==0){
                    temp.push_back(grid[i][j]);
                }
            }
            // reverse for the odd rows for the zigzac pattern 
            if(i%2!=0){
                reverse(temp.begin(), temp.end());
            }
            // adding all the remaining values to the ans
            for(auto itr:temp){
                ans.push_back(itr);
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}