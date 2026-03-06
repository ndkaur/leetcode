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
    int binaryGap(int n) {
        vector<int> idx;
        int  i=1;
        int sz =0;
        while(n>0){
            sz++;
            if(n&1){
                idx.push_back(sz);
            }
            n= n>>1;
        }
        
        for(int i=0; i<idx.size(); i++){
            idx[i]= sz-idx[i];
        }
        reverse(idx.begin(), idx.end());
        
        int mx= 0;
        for(int i=0; i<idx.size()-1; i++){
            int val = idx[i+1]-idx[i];
            mx = max(mx, val);
        }
        return mx;
    }
};


int main(){    
    return 0;
}