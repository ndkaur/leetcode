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
    int maxScore(string s) {
        int n = s.size();
        int lcnt = 0;
        int rcnt = 0;
        for(auto ch:s){
            if(ch=='1')
                rcnt++;
        }
        int mx = 0;
        for(int i=0; i<n-1; i++){
            if(s[i]=='0')
                lcnt++;
            else rcnt--;
            mx = max(mx, lcnt+rcnt);
        }
        return mx;
    }
};

// rcnt = 4 
//i=0 , lcnt =1   mx =  5
// i=1  rcnt = 3  mx = 4 
// i=2 rcnt = 2  mx = 3 
//i=3 rcnt = 1  mx = 2 
// i=4  lcnt =2  mx =2

int main(){

    return 0;
}