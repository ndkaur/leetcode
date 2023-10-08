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
    int minOperations(string s1, string s2, int x) {
        int n = s1.size();
        int m = s2.size();
        vector<int> diff;
        vector<vector<int>> dp(1000, vector<int>(1000,-1));
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i]){
                diff.push_back(i);
            }
        }
        if(diff.size()%2!=0)
            return -1;
        // idx, cnt of indxes left on hopes of finding next index
        return f(0,0,diff, dp, x);
   
    }
    int f(int idx, int cnt, vector<int>& diff,vector<vector<int>>&dp, int& x){
        int n = diff.size();
        
        if(idx==n){
            if(cnt==0)
                return 0;
            return 1e9;
        }
        
        if(dp[idx][cnt]!=-1)
            return dp[idx][cnt];
        
        int ans = 1e9;
        // the flip of i, i+1 will make i+1 invalid so to make it valid we need to keep on making the flips till the next invalid index is encountered
        // i, i+1 will only give valid result if the i has next index where the values are unequal and the total cost will be the number of valid indexex in between til the next invalid index

        if(idx+1<n){ // i,i+1 then diff of all equal elem idxes in between , either min will be x or the diff cause each operation cost 1
           ans =  min(ans, diff[idx+1]-diff[idx] + f(idx+2, cnt, diff, dp, x));
        }

        // if any such index is leaft on hopes of finding the next index , clear it 
        if(cnt>0){
            ans = min(ans, f(idx+1, cnt-1, diff, dp,x));
        }

        // case when we do flip of i, j so we leave i index on hopes of some other jth index
        // but we need to maintain the count of such indexes that we are leaving on hopes of finding the next index ahead

        ans = min(ans, f(idx+1, cnt+1, diff, dp, x) + x); // i , j case 
        
        return dp[idx][cnt] = ans;
    }
};


int main(){

    return 0;
}