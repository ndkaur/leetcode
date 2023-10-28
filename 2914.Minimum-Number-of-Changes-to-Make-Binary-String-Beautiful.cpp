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

lass Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int cnt =0;
        for(int i=0; i<n-1; i+=2){
            if(s[i]!=s[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}