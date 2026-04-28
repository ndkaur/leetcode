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
    int mirrorDistance(int n) {
        int rev = 0;
        int num = n;
        while(n){
            int rem = n%10;
            rev = rev*10+ rem;
            n = n/10;
        }
        cout<<rev;
        int dif = abs(rev-num);
        return dif;
    }
};


int main(){

    return 0;
}