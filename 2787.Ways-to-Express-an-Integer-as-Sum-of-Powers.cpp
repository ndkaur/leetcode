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

class Solution { //time->O(n*n) , space->O(n+n)
public:
    int mod = 1e9+7;
    int f(int target, int numInUse, int power, vector<vector<int>>& dp){
        // base case
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        
        // a case when num in use raise to power gets large then the target 
        // out of bound type of condition
        if(pow(numInUse, power)>target)
            return 0;

        if(dp[target][numInUse]!=-1)
            return dp[target][numInUse];
        
        int notPick = f(target, numInUse+1, power, dp);
        int tempVal = pow(numInUse, power);
        int pick = f(target-tempVal, numInUse+1, power, dp);

        return dp[target][numInUse] = (notPick%mod + pick%mod)%mod;
    }
    int numberOfWays(int n, int x) {
        // we need to try each number from 1 raise to power x and keep on adding it 
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(n, 1, x, dp);
    }
};

int main(){

    return 0;
}