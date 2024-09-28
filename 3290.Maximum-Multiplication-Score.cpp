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
    long long f(vector<int>& a, vector<int>& b, int i, int j){
        int n = a.size();
        int m = b.size();
        if(i==n)
            return 0;
        // backtrack and we reached end then return min so that in future we can take max out of INT_MIN and next ans
        if(j>=m) 
            return INT_MIN;
        
        long long int take =  (long long)a[i]*(long long)b[j] + f(a, b, i+1, j+1);
        // we have to always take i but we can skip the current j value
        long long int ntake =  f(a,b, i, j+1);

        return max(take, ntake);
        
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        return f(a, b, 0,0);
    }
};



class Solution {
public:
    long long f(vector<int>& a, vector<int>& b, int i, int j, vector<vector<long long>>& dp){
        int n = a.size();
        int m = b.size();
        if(i==4)
            return 0;
        // backtrack and we reached end then return min so that in future we can take max out of INT_MIN and next ans
        if(j==m) 
            return -1e12;

        if(dp[i][j]!=-1e12)
            return dp[i][j];
        
        long long int take =  (long long)a[i]*(long long)b[j] + f(a, b, i+1, j+1, dp);
        // we have to always take i but we can skip the current j value
        long long int ntake =  f(a,b, i, j+1, dp);

        return dp[i][j] = max(take, ntake);
        
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        // for the 4 values of a what 4 values we can choose from all the elemts of b
        vector<vector<long long>> dp(4, vector<long long>(m,-1e12));
        return f(a, b, 0,0, dp);
    }
};




int main(){

    return 0;
}