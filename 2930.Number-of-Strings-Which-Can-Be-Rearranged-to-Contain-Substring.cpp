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

// Time compl exity:
// O(n*26)

// Space complexity:
// O(n*26)
class Solution {
public:
    long long mod = 1e9+7;
    long long dp[100001][3][2][2];
    int stringCount(int n) {
        // leet -> l=1, e=2, t=1
        // dp has count of idx,  e, l, t 
        // 1e5+1 , 2 e, l 1, t 1
        // idx ->keep check of len 4 reached or not and if all 4 chars are of leet
        memset(dp, -1, sizeof(dp));
        return (int)(find(0, n, 0, 0, 0)%mod);
    }
    // pick/not pick method
    long long find(int idx, int n, int e, int l, int t){
        // base condition 
        if(idx==n){
            if(e>=2 && l>=1 && t>=1)
                return 1;
            else 
                return 0;
        }
        if(dp[idx][e][l][t]!=-1)
            return dp[idx][e][l][t];

        long long pick = 0;
       
        // a b c d e
        // 0 1 2 3 4
        for(int i=0; i<26; i++){
            // we want len to be 4 having e= 2 times, l and t 1 times
            if(i==4 && e<2){
                pick = (pick + find(idx+1, n, e+1, l, t))%mod;
            }
            else if(i==11 && l<1){
                pick = (pick + find(idx+1, n, e, l+1, t))%mod;
            }
            else if(i==19 && t<1){
                pick = (pick + find(idx+1, n, e, l, t+1))%mod;
            }
            // the char is not freom leet then also move ahead
            else 
                pick = (pick + find(idx+1, n, e, l, t))%mod;
        }

        return dp[idx][e][l][t] = pick;
    }
};


int main(){

    return 0;
}