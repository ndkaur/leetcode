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
    int accountBalanceAfterPurchase(int n) {
        if(n%10 < 5)
            n = (n/10)*10;
        else 
            n = ((n+10)/10)*10;
        return 100 -n;
    }
};

int main(){

    return 0;
}