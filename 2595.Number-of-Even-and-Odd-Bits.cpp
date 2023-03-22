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
    vector<int> evenOddBit(int n) {
        // even odd
        vector<int> ans;
        int odd =0;
        int even =0;
        int pos =0;
        while(n){
            if(n&1){// set bit 
                if(pos&1)
                    odd++;
                else 
                    even++;
            }
            n = n>>1;
            pos++;
        }
        return {even,odd};
    }
};

int main(){

    return 0;
}