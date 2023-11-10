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
    int countHomogenous(string s) {
        int n = s.size();
        int cnt =0;
        int res = 0;
        int mod = 1e9 + 7;
        for(int i=0; i<n; i++){
            if(i>0 && s[i-1]==s[i])
                cnt++;
            else 
                cnt =1;
            res = (res+cnt)% mod;
        }
        return res;
    }
};

int main(){

    return 0;
}