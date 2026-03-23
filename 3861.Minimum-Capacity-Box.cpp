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
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int val =-1;
        int mn = INT_MAX;
        for(int i=0; i<n; i++){
            if(capacity[i]>=itemSize){
                if(capacity[i]<mn){
                    mn = capacity[i];
                    val = i;
                }
            }
        }
        return val;
    }
};


int main(){

    return 0;
}