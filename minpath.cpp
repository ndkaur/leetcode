#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}
//DP
// we have to move from top (0,0) to botttom (m-1,n-1)
// find the min cost sum when travelled respectively.

class Solution0{
    public:
    int minpath(int i,int j,vector<vector<int>> & matrix){
        int n= matrix.size();
        int m= matrix[0].size();
        if(i==(n-1) && j==(m-1))
            return matrix[i][j];
        if(i>=n || j>=m )
            return 1000;
        // only two moments are possible right and bottom 
        int right = matrix[i][j]+ minpath(i,j+1,matrix);
        int bottom = matrix[i][j] + minpath(i+1,j,matrix);
        return min(right,bottom);
    }
};

class Solution{
    public:
    int minpath(int i,int j,vector<vector<int>> & matrix){
        int n= matrix.size();
        int m= matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        ans= minn(0,0,matrix,dp);
        return ans;
    }
    int minn(int i,int j, vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n= matrix.size();
        int m= matrix[0].size();
        if(i==(n-1) && j==(m-1))
            return matrix[i][j];
        if(i>=n || j>=m )
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];   
        int right = matrix[i][j]+minn(i,j+1,matrix,dp);
        int bottom = matrix[i][j]+minn(i+1,j,matrix,dp);
        return dp[i][j]=min(right,bottom); 
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix={{1,2,3},{4,8,2},{1,5,3}};
    int i=0,j=0;
    int ans=sol.minpath(0,0,matrix);
    cout<<ans;
    return 0;
}