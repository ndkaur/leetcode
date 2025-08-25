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
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        if(n==0 || m==0)
            return {};
        vector<int> ans(n*m);
        int row = 0;
        int col = 0;
        for(int i=0; i<n*m; i++){
            ans[i] = mat[row][col];

            if((row+col)%2==0){// even
                // even -> move up right out of bound conditions
                // first row -> col++ , last col -> row++
                if(col==m-1)
                    row++;
                else if(row==0)
                    col++;
                else{
                    row--;
                    col++;
                }
            }
            else{ // odd -> move down left
            // if first col -> row++, last row -> col++
                if(row==n-1)
                    col++;
                else if(col==0)
                    row++;
                else {
                    row++;
                    col--;
                }
            }
        }
        return ans;
    }
};

//      0     1     2
// 0 (0,0) (0,1) (0,2)
// 1 (1,0) (1,1) (1,2)
// 2 (2,0) (2,1) (2,2)


int main(){

    return 0;
}