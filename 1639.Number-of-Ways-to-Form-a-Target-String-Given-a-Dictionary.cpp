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
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int m = target.size();
        int mod = 1e9+7;
        vector<int> dp(m+1,0); // target = abc -> dp of size 3
        dp[0]=1;

        // to count the occurence of each char in each word
        vector<vector<int>> cnt(n, vector<int>(26,0));
        for(string word:words){
            for(int i=0; i<n; i++){
                // word = acca 
                // cnt[0][a-a] = cnt[0][0] = 1
                // cnt[1][c-a] = cnt[1][2] = 1
                cnt[i][word[i] - 'a']++;
            }
        }
        // size of each word is same and we have made the cnt array
        // so now we are not concerned with the char in each word but only the cnt array 
        for(int i=0; i<n; i++){
            // j from behind cause -> dp[3] = dp[2] * cnt
            for(int j=m-1; j>=0; j--){
                dp[j+1] += (int)((long)dp[j] * cnt[i][target[j]-'a'] % mod);
                dp[j+1] %= mod;
            }
        }
        return dp[m];
    } 
};

int main(){

    return 0;
}

// words = ["acca","bbbb","caca"], target = "aba"

// cnt array -> for word acca -> for a =1  , for c ->cnt[1][2] =1 , for c ->cnt[2][2]=1 , for a-> cnt[3][2]=1
//   0 1 2 3
// 0 1 1 1 
// 1 1 1 1
// 2 0 1 2
// 3 2 1 0

// now cnt array is filled 
// lets fill dp array

// dp     0 1 2 3
//        1 0 0 0
// i=0    1 1 0 0    i=0, j=0  target= aba  dp[1] = dp[0]* cnt[j][a] =1 
// i=1    1 2 2 0
// i=2    1 2 6 0