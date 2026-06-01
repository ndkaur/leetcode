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
    int dfs(int i, vector<int>& arr, int d, vector<int>& dp){
        int n = arr.size();
        if(dp[i]!=-1)
            return dp[i];
        
        int ans = 1;
        // right
        for(int j=i+1; j<=min(n-1, i+d); j++){
            // decresing order i>j
            if(arr[i]<=arr[j]){ // not dec order
                break;
            }
            ans = max(ans, 1+ dfs(j, arr, d, dp));
        } 
        // left
        for(int j=i-1; j>=max(0, i-d); j--){
            // dec i>j
            if(arr[j]>=arr[i]){
                break;
            }
            ans = max(ans, 1+dfs(j, arr, d, dp));
        }

        return dp[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 1;

        for(int i=0; i<n; i++){
            ans = max(ans, dfs(i,arr, d,dp));
        }
        return ans;
    }
};


int main(){

    return 0;
}