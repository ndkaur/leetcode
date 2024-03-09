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


// binary  search
class Solution {
public:
    int find(vector<vector<int>>& arr, int target){
        int cnt = 0;
        
        // val>target
        for(int i=0; i<arr.size(); i++){
            int idx = upper_bound(arr[i].begin(), arr[i].end(), target) - arr[i].begin();
            cnt += idx;
        }
        return cnt;
    }
    int matrixMedian(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int l = 0; // lowest possible median value
        int r = 1e6; // highest possible median value

        int median = (n*m)/2;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            int cnt = find(grid,mid);
            
            if(cnt <= median){
                l = mid+1;
            }
            else 
                r = mid-1;
        }
        return l;
    }
};

// [1,1,2]
// [2,3,3]
// [1,3,4]

int main(){

    return 0;
}