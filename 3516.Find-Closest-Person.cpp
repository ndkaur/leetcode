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
    int findClosest(int x, int y, int z) {
        if(abs(x-z)==abs(y-z))
            return 0;
        else if(abs(x-z)<abs(y-z))
            return 1;
        else 
            return 2;
    }
};


int main(){

    return 0;
}