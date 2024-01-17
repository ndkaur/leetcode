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


class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int idx = 0; // the index where condtion wasnt valid 
        long long cnt = 1;
        
        for(int i=1; i<n; i++){
            if(prices[i]+1!=prices[i-1]){
                idx = i;
                cnt++;
            }
            else // equal , condition valid
                cnt+= i-idx+1;
        }
        return cnt;
    }
};

// i = 1 , 3==2+1 so cnt = 1+ (1-0)+1 = 3=cnt 
// i = 2, 2 =1+1 so cnt = 3 + (2-0)+1 = 3+2+1=6
// i= 3, 3 !=1+1  so idx = 3, cnt++ = cnt=7



int main(){
     Solution sol;
     vector<int> prices={3,2,1,4};
     long long ans  = sol.getDescentPeriods(prices);
     cout<<ans;
   return 0;
}