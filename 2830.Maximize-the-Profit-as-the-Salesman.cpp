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


class Solution { //O(nlogn) + O(n)
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int sz = offers.size();
        sort(offers.begin(), offers.end());
        vector<int> dp(sz,-1);
        vector<int> start;
        for(int i=0; i<sz; i++){ // push all the starting limits s1 
            start.push_back(offers[i][0]);
        }
        return solve(0,start, dp, offers);
    }
    int solve(int idx, vector<int>& start, vector<int>& dp, vector<vector<int>>& offers){
        int n = offers.size();
        if(idx >= n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];

        int notPick = solve(idx+1, start, dp, offers);

        // finding which idx will dp move to if we pick up the offer
        int end = offers[idx][1]; // {s1,e1}
        int ub = upper_bound(start.begin(), start.end(), end) - start.begin();
        // finding the ub = elem > target
        //so that we reach to that idx where it has no overlapping 
        int pick = offers[idx][2] + solve(ub , start, dp, offers);

        return dp[idx] = max(pick, notPick);
    }
};


int main(){

    return 0;
}