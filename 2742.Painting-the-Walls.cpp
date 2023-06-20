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
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int  n = cost.size();
        // dp ={idx, walls left}
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        // cost is the total of walls painted by the paid painter
        return find(n-1, n, cost, time, dp);
    }
    int find(int idx, int walls, vector<int>&cost, vector<int>& time, vector<vector<int>>& dp ){
        if(walls<=0) // no walls , walls is the size of array 
            return 0;
        if(idx<0) 
            return 1e9;
        if(dp[idx][walls]!=-1)
            return dp[idx][walls];
        // not take means letting it for the free painter to paint
        int notTake = find(idx-1,walls,cost, time, dp);
        // painter by the paid painter
        int take = cost[idx] + find(idx-1, walls-time[idx]-1, cost, time ,dp);
        return dp[idx][walls] = min(take, notTake);
    }
};

int main(){

    return 0;
}