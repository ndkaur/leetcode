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
    int minimizedStringLength(string s) {
        int n = s.size();
        map<char,int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        int cnt =0;
        for(auto itr:mp){
            if(itr.second>1)
                cnt+= itr.second - 1;
        }
        return n-cnt;
    }
};


int main(){

    return 0;
}