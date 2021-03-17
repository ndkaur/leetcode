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

class Solution0{
    public:
    int knapsack(int idx,int weight, vector<int>& values,vector<int> & weights ){
        int n=weights.size();
        if(idx>=n)  return 0; // reached out of list 
        if(weight==0) return 0; // reached end 
        if(weights[idx]<=weight){
            int left = values[idx]+knapsack(idx+1,weight-weights[idx],values,weights);
            int right = knapsack(idx+1,weight,values,weights);
            return max(left,right);
        }
        else
            return knapsack(idx+1,weight,values,weights);    
        return -1;
    }
};

class Solution{
    vector<vector<int>> dp;
    public:
    int knapsack(int idx,int w, vector<int>& values,vector<int> & weights ){
        int n=weights.size();
        vector<vector<int>> dp= vector<vector<int>>(n,vector<int>(w+1,-1));
        if(idx>=n)  return 0; // reached out of list 
        if(w==0) return 0; // reached end 
        if(dp[idx][w]!=-1)
            return dp[idx][w];
        if(weights[idx]<=w){
            int left = values[idx]+knapsack(idx+1,w-weights[idx],values,weights);
            int right = knapsack(idx+1,w,values,weights);
            return dp[idx][w]=max(left,right);
        }
        else
            return dp[idx][w]= knapsack(idx+1,w,values,weights);    
        return -1;
    }
};


int main(){
   Solution sol;
   vector<int> values={100,100,180};
   vector<int> weights={25,25,30};
   int w=50;
   int idx=0;
   int ans=sol.knapsack(idx,w,values,weights );
   cout<<ans;
}