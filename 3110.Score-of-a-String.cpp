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
    int scoreOfString(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n-1; i++){
            int diff = abs((s[i]-'a')- (s[i+1]-'a'));
            ans+=diff;
        }
        return ans;
    }
};

int main(){

    return 0;
}