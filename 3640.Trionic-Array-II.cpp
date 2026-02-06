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
    typedef long long ll;
    long long solve(int i, int state, vector<int>& nums, vector<vector<ll>>& dp){
        int n = nums.size();
        if(i==n){
            if(state==3){
                return 0;
            }
            else 
                return LLONG_MIN/2;
        }

        if(dp[i][state]!= LLONG_MIN){
            return dp[i][state];
        }

        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        if(state==0){ // we can only skip when th trionic hasnt begun , once it begin we have to take lemts continously 
            skip = solve(i+1,0, nums, dp);
        }

        if(state==3){
            take= nums[i];
        }

        if(i+1<n){
            int curr = nums[i];
            int next = nums[i+1];

            if(state==0 && curr<next){// begining state=0
                take = max(take, curr + solve(i+1, 1, nums, dp));
            }
            else if(state==1){ // then can continue inc or start dec
                if(curr<next){ // inc order
                    take = max(take, curr + solve(i+1, 1, nums, dp));
                }
                else if(curr>next){ // dec order
                    take= max(take, curr+solve(i+1, 2, nums, dp));
                }
            }
            else if(state==2){ // can continue dec or enter next state 3
                if(curr>next){ // dec 2
                    take = max(take, curr+ solve(i+1, 2, nums, dp));
                }
                else if(curr<next){ // inc state=3
                    take = max(take, curr+solve(i+1, 3, nums, dp));
                }
            }
            else if(state==3 && curr<next){
                take = max(take, curr+solve(i+1, 3, nums, dp));
            }
        }

        return dp[i][state] = max(take, skip);
    }


    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        // we have choice from which idx to start but once we have started from that index we cant break inbetween until the loop for inc dec and inc is completed 
        vector<vector<ll>> dp(n+1, vector<ll>(4, LLONG_MIN));
        // i, state->start 0, inc 1, dec2, inc 3
        return solve(0,0,nums, dp);
    }
};



int main(){

    return 0;
}