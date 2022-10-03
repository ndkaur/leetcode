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
    int commonFactors(int a, int b) {
        int ans =0;
        int mx = max(a,b);
        for(int i=1; i<=mx; i++){
            if(a%i == 0 && b%i == 0){
                ans++;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}