#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}


class Solution0 {
public:
    int countVowelPermutation(int n) {
        vector<long long> acount(n);
        vector<long long> ecount(n);
        vector<long long> icount(n);
        vector<long long> ocount(n);
        vector<long long> ucount(n);

        acount[0]=1L;
        ecount[0]=1L;
        icount[0]=1L;
        ocount[0]=1L;
        ucount[0]=1L;

        int MOD = 1000000007;
        for(int i=1;i<n;i++){
            acount[i]= (ecount[i-1]+ucount[i-1]+icount[i-1])% MOD;
            ecount[i] = (acount[i-1]+icount[i-1]) % MOD;
            icount[i] = (ecount[i-1]+ocount[i-1]) % MOD;
            ocount[i] = (icount[i-1])% MOD;
            ucount[i] = (ocount[i-1] + icount[i-1]) % MOD;
        }
        long long result =0L;
        result = (acount[n-1] + ecount[n-1] + icount[n-1] + ocount[n-1] + ucount[n-1] ) % MOD;
        return (int)result; 
    }
};


class Solution {
public:
    int countVowelPermutation(int n) {
       long long acount=1, ecount=1,icount=1,ocount=1,ucount=1;
       int MOD = 1000000007;
       for(int j=1;j<n;j++){
           long long a= (ecount+icount+ucount)%MOD;
           long long e =(acount+icount)%MOD;
           long long i= (ecount+ocount)%MOD;
           long long o= (icount)%MOD;
           long long u = (icount+ocount)%MOD;
           acount = a;
           ecount =e;
           icount =i;
           ocount =o;
           ucount =u;
       }
       long long result = (acount+ecount+icount+ocount+ucount)%MOD;
       return (int)result;
    }
};

int main(){
    Solution sol;
    int n= 1;
    int ans = sol.countVowelPermutation(n);
    cout<<ans;
    return 0;
}