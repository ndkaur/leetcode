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


class Solution { // tle 
public:
    int mod = 1e9+7;
    int dp[201][201][2];
    int solve(int onecnt, int zerocnt, bool lastisone, int limit){
        if(onecnt==0 && zerocnt==0)
            return 1;
        
        if(dp[onecnt][zerocnt][lastisone]!=-1){
            return dp[onecnt][zerocnt][lastisone];
        }

        int ans = 0;
        if(lastisone==true){ // add zero
            for(int len=1; len<=min(zerocnt, limit); len++){
                ans = (ans+ solve(onecnt, zerocnt-len, false, limit)%mod);
            }
        }
        else { // add one
            for(int len=1; len<=min(onecnt, limit); len++){
                ans = (ans+ solve(onecnt-len, zerocnt, true, limit)%mod);
            }
        }

        return dp[onecnt][zerocnt][lastisone] = ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        // we cant take the continous no of 0/1s whose count is greater than limit
        // eg-> limit=2, 01110  , 111 is invalid 
        // ones, zeros, last is one->bool
        memset(dp, -1, sizeof(dp));
        int startWithOne = solve(one, zero, false, limit);
        int startWithZero = solve(one,zero, true, limit);

        return (startWithOne + startWithZero) %  mod;
    }
};


class Solution1 {
public:
    int mod = 1e9+7;
    int numberOfStableArrays(int zero, int one, int limit) {
        // we cant take the continous no of 0/1s whose count is greater than limit
        // eg-> limit=2, 01110  , 111 is invalid 
        // ones, zeros, last is one->bool
        int dp[201][201][2];


        dp[0][0][0] =1;
        dp[0][0][1] =1;

        for(int o=0; o<=one; o++){
            for(int z=0; z<=zero; z++){
                if(o==0 && z==0)
                    continue;
                
                int ans = 0;
                // last == one, chheck for 0 now
                for(int len=1; len<=min(z,limit); len++){
                    ans = (ans + dp[o][z-len][0])%mod;
                }
                dp[o][z][1] = ans;

                ans = 0; 
                // last==zero
                for(int len=1; len<=min(o,limit); len++){
                    ans = (ans + dp[o-len][z][1])%mod;
                }
                // dp[o][z][0] means last one last_was_one= false, means last added elm is not 1 ie it was 0 
                dp[o][z][0] = ans;
            }
        }
        int startWithOne = dp[one][zero][false];
        int startWithZero = dp[one][zero][true];

        return (startWithOne + startWithZero) %  mod;
    }
};



int main(){

    return 0;
}