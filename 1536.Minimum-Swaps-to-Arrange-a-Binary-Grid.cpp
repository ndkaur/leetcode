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
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> zeros(n,0); // count the 0 from the end of row
        
        for(int i=0; i<n; i++){
            int j =n-1;
            int cnt =0;
            while(j>=0 && grid[i][j]==0){
                cnt++;
                j--;
            }
            zeros[i] = cnt;
        }

        int ans =0;
        for(int i=0; i<n; i++){
            int required_swaps = n-i-1;
            int j = i; // check if that required cnt is there in array then swap
            while(j<n && zeros[j]<required_swaps){
                j++;
            }
            if(j==n){
                return -1; // not found
            }
            ans += j-i; // found and swap

            while(j>i){ // actual swap in array is also required
                swap(zeros[j], zeros[j-1]);
                j--;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}