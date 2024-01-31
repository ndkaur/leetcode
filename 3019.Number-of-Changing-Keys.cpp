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
    int countKeyChanges(string s) {
        int n = s.size();
        int cnt=0;
        char prev='\0';
        for(char c:s){
            if(tolower(c)!=tolower(prev)){
                cnt++;
            }
            prev=c;
        }
        return cnt-1;
    }
};

int main(){

    return 0;
}