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

// without collison  = total - no collison 
// total = 2^n  because each monkey has 2 options clock or anticlock 
// no coillison in 2 cases possible either all clockwise or all anticlockwise
// ans = 2^n - 2

class Solution {
public:
    int monkeyMove(int n) {
        long long res = 1;
        long long base = 2; // 2^n
        long long mod = 1e9+7;
        // finding pow 
        while(n){
            if(n%2){
                res = (res*base) % mod;
            }
            base = (base * base) % mod;
            n = n/2;
        }
        int k = res;
        return (k-2 + mod) % mod;
    }
};

int main(){

    return 0;
}