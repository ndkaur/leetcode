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
    int matrixMedian(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(), arr.end());
        if(arr.size()%2==1){
            return arr[arr.size()/2];
        }
        else{
            int half = arr.size()/2;
            return (arr[half] + arr[half-1])/2;
        }
        return -1;
    }
};

class Solution {
  public:
    int elmgreater(vector<vector<int>>& mat, int mid){
        // find cnt of elm greater than mid in row wise sorted matrix
        int cnt =0;
        for(vector<int> row:mat){
            int n = row.size();
            cnt += upper_bound(row.begin(), row.end(), mid)-row.begin();
          
        }
        return cnt;
       
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int req = (n*m)/2;
        // the no median will be btw the min and max number of the matrix
        
        int l = INT_MAX;
        int r = INT_MIN;
        for(int i=0; i<n; i++){
            l = min(l, mat[i][0]);
            r = max(r, mat[i][m-1]);
        }
        int ans = -1;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            int cnt = elmgreater(mat, mid);
            if(cnt<=req){
                // median is greater than mid
                l = mid+1;
            }
            else { // cnt>req
                ans =  mid;
                r = mid-1;
            }
        }
        return ans;
    }
};




// [1,1,2]
// [2,3,3]
// [1,3,4]

int main(){

    return 0;
}