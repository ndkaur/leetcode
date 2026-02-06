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



class Solution { // O(logn)
public:
    int countMonobit(int n) {
        int cnt = 1; // for 0
        int val = 1;
        // we only iterate on 1, 3, 7, that is all set bits 
        // 1<<1= 10 |1 = 11 
        // 11<<1 = 110 | 1 = 111 all same bits
        while(val<=n){
            val = (val<<1) | 1;
            cnt++;
        }
        return cnt;
    }
};

//all 0 = 0
// all 1 -> 1, 3, 7 means 2^2-1  , 2^k -1



int main(){

    return 0;
}