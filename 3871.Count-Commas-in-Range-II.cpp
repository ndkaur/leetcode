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
    long long countCommas(long long n) {
        long long ans = 0;
        long long val = 1000;

        // abs(n-1000)+1
        while (val <= n) {
            ans += (n - val + 1);
            val *= 1000;
        }
        return ans;
    }
};

// size
// 15 = 1 
// 14->12 = 4
// 11->9 = 3
// 8->6 = 2
// 5->3 = 1


int main(){

    return 0;
}