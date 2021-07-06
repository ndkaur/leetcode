#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> dp(n+1);
        vector<int> ptrs(m,1);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int mn = INT_MAX;
            for(int j=0;j<m;j++){
                mn=min(mn,primes[j]* dp[ptrs[j]]);
            }
            dp[i]=mn;
            for(int j=0;j<m;j++){ // the ptr whose value is min we increase it to next index
                if(primes[j]* dp[ptrs[j]] == mn)
                    ptrs[j]++;
            }
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
    vector<int> primes={2,7,13,19};
    int n = 12;
    int ans = sol.nthSuperUglyNumber(n, primes);
    cout<<ans;
    return 0;
}