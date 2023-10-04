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
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int alice =0;
        int bob =0;

        for(int i=1; i<n-1; i++){
            if(colors[i-1]=='A' && colors[i]=='A' && colors[i+1]=='A'){
                alice++;
            }
            else if(colors[i-1]=='B' && colors[i]=='B' && colors[i+1]=='B'){
                bob++;
            }
        }

        if(alice>bob)
            return true;
        return false;
    }
};

int main(){

    return 0;
}