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
    bool hasAllCodes(string s, int k) {
        int  n = s.size();
        set<string> st;
        for(int i=0; i<=n-k; i++){
            string val = s.substr(i, k);
            st.insert(val);
        }
        // no of subting of size k = 2^k
        return st.size()==pow(2,k);
    }
};


int main(){

    return 0;
}