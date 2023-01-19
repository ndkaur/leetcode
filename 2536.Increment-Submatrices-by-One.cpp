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

class Solution { // tle
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int sz = queries.size();
        vector<vector<int>> matrix(n, vector<int>(n,0));
        for(auto query : queries){
            int r1 = query[0];
            int c1 = query[1];
            int r2 = query[2];
            int c2 = query[3];
                
            for(int i = r1; i <= r2; i++){
                for(int j = c1; j <= c2; j++){
                    matrix[i][j]++;
                }
            }
        }
        return matrix;
    }
};

// tc -> O(q*n)+ O(n^2)
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int sz = queries.size();
        vector<vector<int>> mat(n, vector<int>(n,0));
        for(int i=0; i<sz; i++){
            for(int j = queries[i][0]; j<= queries[i][2] ; j++){
                // (1,1) (1,2)
                // (2,1) (2,2)
                mat[j][queries[i][1]]++; // startin gpoint +1 
                if(queries[i][3] + 1 != n)
                    mat[j][queries[i][3]+1]--;// ending point ahead as -1
            }
        }
        // calculate the prefix sum
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                mat[i][j] += mat[i][j-1];
            }
        }
        return mat;
    }
};

// tc -> O(q)+ O(n^2)   , q is size of queries
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n,0));
        for(auto q:queries){
            int r1 = q[0];  // (r1,c1) =1 // start as 1 
            int c1 = q[1];  // (r2+1,c2+1) = 1  // end +1 as 1 
            int r2 = q[2];  // (r1, c2+1) = -1 // middle as -1
            int c2 = q[3];  // (r2+1 , c1) = -1 // middle as -1
            // (r1,c1) (r2,c2)  
            mat[r1][c1] += 1; // start 
            if(r2+1 < n && c2+1 < n) // end+1
                mat[r2+1][c2+1] += 1; 
            if(r2+1 < n)
                mat[r2+1][c1]  -= 1;
            if(c2+1 < n)
                mat[r1][c2+1] -= 1;
        }
        // finding prefix sum row wise
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                mat[i][j] += mat[i][j-1];
            }
        }
        // finding prefix sum col wise
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                mat[i][j] += mat[i-1][j];
            }
        }
        return mat;
    }
};


int main(){

    return 0;
}