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
    int minBitFlips(int start, int goal) {
        int num =0;
        num = start ^ goal;
        int ans =0;
        while(num){
            if(num&1)
                ans++;
            num = num>>1;
        }
        return ans;
    }
};

int main(){

    return 0;
}