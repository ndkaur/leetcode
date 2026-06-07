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
    int f(int i, vector<vector<int>>& item, int budget, vector<vector<int>>& dp, int mn, int n, vector<int>& fact){
        if(i>=n) { // out of bound, but still have budget then buy more copies of the smallest cost with the remianing budget
            return budget/mn;
        }

        if(dp[i][budget]!=-1)
            return dp[i][budget];
        
        int take = 0;
        if(budget>=item[i][1]){
            // items we can take = factors + next idx
            take = fact[i] + f(i+1, item, budget-item[i][1], dp, mn, n, fact);
        }

        int not_take = f(i+1, item, budget, dp, mn, n, fact);
        return dp[i][budget] = max(take,  not_take);

    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> fact(n,0);
        // items -> factor, cost
        int mn_cost = INT_MAX;
        for(int i=0; i<n; i++){
            mn_cost = min(mn_cost, items[i][1]);
            for(int j=0; j<n; j++){ // factor of self also included 2%2 incude 
                if(items[j][0]%items[i][0]==0){
                    fact[i]++;
                }
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(budget+1,-1));
        return f(0, items, budget, dp, mn_cost,n, fact);
    }
};


int main(){

    return 0;
}