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
    long long minCuttingCost(int n, int m, int k) {
        if(n==0 || m==0 || k==0)
            return 0;
        long long cost =0;

        if(n<=k && m<=k)
            return 0;

        if(n>k && m<=k){
            long long diff = n-k;
            cost += (long long)diff*k;
        }
        if(m>k && n<=k){
            long long diff = m-k;
            cost += (long long)(diff*k);
        }
        return cost;
    }
};

int main(){

    return 0;
}