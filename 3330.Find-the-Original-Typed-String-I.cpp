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
    int possibleStringCount(string word) {
        int n = word.size();
        int cnt = n;
        for(int i=1; i<n; i++){
            if(word[i]!=word[i-1]){
                cnt--;
            }
        }
        return cnt;
    }
};


int main(){

    return 0;
}