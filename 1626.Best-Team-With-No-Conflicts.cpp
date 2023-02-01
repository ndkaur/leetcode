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
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        int ans =0;
        vector<int> dp(n,0);
        vector<pair<int,int>> players; // age, score
        for(int i=0; i<n; i++){
            players.push_back({ages[i], scores[i]});
        }
        // sort players according to age in ncresing order 
        sort(players.begin(), players.end());
        // now conflict happen when prev smaller age has higher score than current large age player with smaller score
        for(int i=0; i<n; i++){
            dp[i] = players[i].second; // firstly giving actual value
            for(int j=0; j<i; j++){ // checking for conlict 
            // if no cnlfict then check the new dp value
                // prev score < curr score
                if(players[j].second <= players[i].second){
                    // for each i we check prev j and find the max of all by adding them to the original answer 
                    dp[i] = max(dp[i], dp[j] + players[i].second);
                }
            }
            ans = max(ans, dp[i]);
        } 
        return ans;
    }
};  

int main(){

    return 0;
}