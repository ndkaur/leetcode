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


class Solution0 {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        map<char,vector<int>> mp;
        // at what index the chars of ring are existing 
        for(int i=0; i<n; i++){
            mp[ring[i]].push_back(i);
        }
        return f(0, 0, ring, key, mp);
    }
    int f(int i, int j, string& ring, string& key, map<char,vector<int>>& mp){
        int n = ring.size();
        if(j==key.size())
            return 0;
        int ans = INT_MAX;
        // finding the idx of key ch in ring 
        for(int idx:mp[key[j]]){
            int dist = abs(i-idx);
            ans = min(ans, min(dist, n-dist) + f(idx, j+1, ring, key, mp)); 
        }
        return ans+1;
    }
};


class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        map<char,vector<int>> mp;
        // at what index the chars of ring are existing 
        for(int i=0; i<n; i++){
            mp[ring[i]].push_back(i);
        }
        vector<vector<int>> dp(n, vector<int>(key.size(),-1));
        return f(0, 0, ring, key, mp, dp);
    }
    int f(int i, int j, string& ring, string& key, map<char,vector<int>>& mp, vector<vector<int>>& dp){
        int n = ring.size();
        if(j==key.size())
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        int ans = INT_MAX;

        // finding the idx of key ch in ring 
        for(int idx:mp[key[j]]){
            int dist = abs(i-idx);
            ans = min(ans, min(dist, n-dist) + f(idx, j+1, ring, key, mp, dp)); 
        }
        return dp[i][j] = ans+1;
    }
};



int main(){

    return 0;
}