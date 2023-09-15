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
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int lsum =0;
        for(int i=1; i<=n; i++){
            lsum += i;
            if(lsum ==sum)
                return i;
            sum -= i;
        }
        return -1;
    }
};  

int main(){

    return 0;
}