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
    bool check(vector<long long>& arr, long long sum ){
        long long lsum =arr[0];
        long long rsum = sum-lsum;

        for(int i=1; i<arr.size(); i++){
            if(lsum==rsum)
                return true;
            else if(lsum>rsum)
                return false;

            lsum += arr[i];
            rsum -= arr[i];
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> row(n,0);
        vector<long long> col(m,0);

        long long total = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                row[i] += grid[i][j];
                total += grid[i][j];
                col[j]+= grid[i][j];
            }
        }

        if(total%2)
            return false;

        if(check(row, total))
            return true;
        if(check(col, total))
            return true;

        return false;
    }
};




int main(){

    return 0;
}