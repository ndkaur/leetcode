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
        long long f(int i, vector<vector<int>>& ques, vector<long long>& dp){
            int n = ques.size();
            if(i>=n)
                return 0;
            if(dp[i]>0)
                return dp[i];
            int val = ques[i][0];
            int jump = ques[i][1];
            // skip , notskip
            return dp[i] = max(f(i+1,ques, dp), val + f(i+jump+1, ques, dp));
        }
        long long mostPoints(vector<vector<int>>& ques) {
            int n = ques.size();
            vector<long long> dp(n,0);
            return f(0,ques, dp);
        }
    };  

int main(){

    return 0;
}