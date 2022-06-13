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

//  828 question 

// t-> O(n)  s->O(n)
class Solution {
public:
    long long appealSum(string s) {
        int n= s.size();
        vector<long>dp(n+1);
        vector<int> lastIdx(26,-1);
        long sum=0;
        for(int i=0;i<n;i++){
            int charAt= s[i]-'a'; 
            dp[i+1]= dp[i]+(i-lastIdx[charAt]);
            sum+= dp[i+1];
            // update the last occurence index of char
            lastIdx[charAt]=i;
        }
        return sum;
    }
};

//  have to find the subsets and count the lenght of each subset by counting the duplicates only ones 
//  dp[i+1]=  dp[i]+1 +( i- last index -1) 
//  dp[i]+1 -> adding 1 because every time 1 more new char is added in the sequence
//  => dp[i+1]=  dp[i] + i- lastidx 
//  if not repeated so lastidx = -1 then dp[i+1]= dp[i] + (i-(-1)) = dp[i]+ (i+1)
//  if repeated ->  dp[i+1]= dp[i]+(i- lstidx)
//  lastidx =   0,  1,  2,  3,  4,       26    => let char be c=  c-'a' = 2-0=2   
//           { -1, -1, -1, -1, -1 ..... -1 }  


int main(){
    Solution sol;
    string s="code";
    int ans= sol.appealSum(s);
    cout<<ans;
    return 0;
}