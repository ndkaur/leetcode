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
    vector<string> generatePossibleNextMoves(string curr) {
        vector<string> ans;
        int n = curr.size();
        for(int i=0; i<n-1; i++){
            if(curr[i]=='+' && curr[i+1]=='+'){
                curr[i]=curr[i+1] = '-';
                ans.push_back(curr);
                curr[i]=curr[i+1] = '+';
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}