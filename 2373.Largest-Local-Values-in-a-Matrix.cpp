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
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n= grid.size();
        
        vector<vector<int>> ans(n-2 , vector<int>(n-2));
        
        for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans.size(); j++){

                int mx= INT_MIN;
                for(int row=i; row<i+3; row++){
                    for(int col=j; col<j+3; col++){
                        mx = max(mx, grid[row][col]);
                    }
                }
                ans[i][j]= mx;
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n= grid.size();
        
        vector<vector<int>> ans(n-2 , vector<int>(n-2));
        
        for(int i=0; i<n-2; i++){
            for(int j=0; j<n-2; j++){
                ans[i][j] = find(i,j, grid);                
            }
        }
        return ans;
    }
    int find(int i, int j , vector<vector<int>>& grid){
        int mx= INT_MIN;
        for(int row=i; row<i+3; row++){
            for(int col=j; col<j+3; col++){
                mx= max(mx, grid[row][col]);
            }
        }
        return mx;
    }
};



int main(){

    return 0;
}