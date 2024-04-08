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
    string getSmallestString(string s, int k) {
        int n = s.size();

        for(auto& ch:s){
            int left = ch-'a';
            int right = 'z'-ch+1;
            // distance is in 
            int mn = min(left, right);
            if(k>=mn){
                // distance we consumed
                k-= mn;
                ch = 'a';
            }
            else{ // k < mn
                ch = ch-k;
                k = 0;
            }
        }
        return s;
    }
};

int main(){

    return 0;
}