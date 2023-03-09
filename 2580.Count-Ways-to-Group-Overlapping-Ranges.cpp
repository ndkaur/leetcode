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
    long long mod = 1e9+7;
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size();
        long long ans =2; // inititally two intervals we have 

        sort(ranges.begin(), ranges.end());

        int l1 =ranges[0][0];
        int r1 = ranges[0][1];
        
        for(int i=1; i<n; i++){
            int l2 = ranges[i][0];
            int r2 = ranges[i][1];

            if(l1<=r2 && l2<=r1){ // overlap
                l1 = min(l1,l2);
                r1 = max(r1,r2);
            }
            else{ // non overlap 
                r1 = r2; // so the value of first limit will be the current limit 
                ans = (ans*2)%mod;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}