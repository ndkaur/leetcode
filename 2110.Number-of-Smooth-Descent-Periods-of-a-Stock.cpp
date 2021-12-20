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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}


class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n= prices.size();
        vector<int> dp(n);
        dp[0]=1;
        long long ans =1;
        for(int i=1;i<n;i++){
              if(prices[i]==prices[i-1]-1){
                    dp[i]= dp[i-1]+1;
              }
              else {
                  dp[i]=1;
              }
            ans += dp[i];
        }
        return ans;
    }
};

int main(){
     Solution sol;
     vector<int> prices={3,2,1,4};
     long long ans  = sol.getDescentPeriods(prices);
     cout<<ans;
   return 0;
}