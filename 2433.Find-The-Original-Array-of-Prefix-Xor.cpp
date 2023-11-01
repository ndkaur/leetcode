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
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        for(int i=n-1; i > 0; i--){
            pref[i] ^= pref[i - 1];
        }
        return pref;
    }
};

// 1 ^ 11 = 10  = 2
// 11 ^ 0 = 11 = 3
// 0 ^ 10 = 10 = 2 
// 10 ^ 101 =  111 = 7
// 5 

int main(){

    return 0;
}