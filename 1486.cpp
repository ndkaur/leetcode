#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    int xorOperation(int n, int start) {
        int result=0;
        while(n--){
            result=result^start;
            start=start+2;
        }
        return result;
    }
};


int main(){
    Solution sol;
    int n=5, start=0;
    int result;
    sol.xorOperation(n,start);
    cout<<result;
    return 0;
}