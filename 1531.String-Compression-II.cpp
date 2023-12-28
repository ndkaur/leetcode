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

class Solution0 { // tle basic recursion 
public:
    int f(int idx, char prev, int curCharFreqCount, string& s, int k){
        if(k<0)
            return 1e9;

        if(idx >= s.size()) // out of bound
            return 0;
        
        int ans =  1e9;

        // 3 cases 
        // 1 -> we delete curr char if k is remaining 
        // 2 -> if curr and prev char not same then one more new char ie the len will increase ie overall ans will increse 
        // 3 -> if curr and prev same then increase the count
        // -> charCount is either 1 or 9 then cnt will increase by 1
        // ->else just increse the cnt

        // 1 we delete curr char if k is remaining 
        ans = min(ans, f(idx+1,prev, curCharFreqCount, s, k-1));

        // 2 -> if curr and prev char not same then ans will increase
        if(s[idx]!=prev){
            ans = min(ans, 1+f(idx+1,s[idx], 1, s, k));
        }
        
        // 3 when curr and prev equal 
        else{
            // so if its like a12 or a10 then a the ans length will increse as its a double digit number and the cnt of ahcr also increses
            if(curCharFreqCount==1 || curCharFreqCount==9 || curCharFreqCount==99){
                ans = min(ans, 1+f(idx+1, prev, curCharFreqCount+1,s, k));
            } 
            // the char is still in single digit after including the curr char count
           else{
                ans = min(ans, f(idx+1, prev, curCharFreqCount+1, s, k));
            }
        }
        return ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        // aabbcc -> a2b2c2 if eg k=2 then a2b2 discard c
        // idx, prev, currcharCount, s, k
        return f(0,'#', 0, s, k);
    }
};

// as we observe all 4 parameters are changing 
// ie  idx n, prev char, curr char count, k value  
// a 4d dp is required

class Solution { // tle basic recursion 
public:
    int f(int idx, char prev, int curCharFreqCount, string& s, int k, vector<vector<vector<vector<int>>>>& dp){
        if(k<0)
            return 1e9;

        if(idx >= s.size()) // out of bound
            return 0;

        // if the cnt became 2 digit then it doesnt matter if its 10 ...99 
        // cause length will be 2 only  
        if(curCharFreqCount >= 10)
            curCharFreqCount = 10;
        
        if(dp[idx][prev-'a'][curCharFreqCount][k]!=-1)
            return dp[idx][prev-'a'][curCharFreqCount][k];

        int ans =  1e9;

        // 3 cases 
        // 1 -> we delete curr char if k is remaining 
        // 2 -> if curr and prev char not same then one more new char ie the len will increase ie overall ans will increse 
        // 3 -> if curr and prev same then increase the count
        // -> charCount is either 1 or 9 then cnt will increase by 1
        // ->else just increse the cnt

        // 1 we delete curr char if k is remaining 
        ans = min(ans, f(idx+1,prev, curCharFreqCount, s, k-1,dp));

        // 2 -> if curr and prev char not same then ans will increase
        if(s[idx]!=prev){
            ans = min(ans, 1+f(idx+1,s[idx], 1, s, k,dp));
        }
        
        // 3 when curr and prev equal 
        else{
            // so if its like a12 or a10 then a the ans length will increse as its a double digit number and the cnt of ahcr also increses
            if(curCharFreqCount==1 || curCharFreqCount==9 ){
                ans = min(ans, 1+f(idx+1, prev, curCharFreqCount+1,s, k,dp));
            } 
            // the char is still in single digit after including the curr char count
           else{
                ans = min(ans, f(idx+1, prev, curCharFreqCount+1, s, k,dp));
            }
        }
        return dp[idx][prev-'a'][curCharFreqCount][k] =  ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        // aabbcc -> a2b2c2 if eg k=2 then a2b2 discard c
        // idx, prev, currcharCount, s, k
        int n = s.size();
        if(n==k) // then remove all chars and min len is 0 
            return 0;
        
        // case where all the chars are same 
        bool allSame = true;
        for(int i=1; i<n; i++){
            if(s[i]!=s[i-1]){
                allSame = false;
                break;
            }
        }

        if(allSame){ // all chars are same then remove the k chars and remaining length will be the answer as the minimum length
            n = n-k;
            if(n==1)
                return 1;
            // a15 so cnt the chars in n +1  and add 1 for char a 
            return log10(n) + 1 + 1;
        }
        // int dp[n+1][27][11][101];
        //  idx, prev char, char cnt, k 
        vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(27, vector<vector<int>>(11, vector<int>(101, -1))));
        // using the prev char as the cnt of it like prev-'a' 
        return f(0,'z' + 1, 0, s, k, dp);
    }
};



int main(){

    return 0;
}