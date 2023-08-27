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
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int lcnt =0;
        int rcnt =0;
        int ans =0;
        
        for(int i=0; i<n; i++){
            if(moves[i]=='L'){
                lcnt++;
            }
            if(moves[i]=='R'){
                rcnt++;
            }
            if(moves[i]=='_')
                ans++;
        }
        ans += max(lcnt, rcnt) - min(lcnt,rcnt);
        return ans;
    }
};


int main(){

    return 0;
}