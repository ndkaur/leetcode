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
    string finalString(string s) {
        int n = s.size();
        string temp ;
        for(int i=0; i<n; i++){
            if(s[i]!='i'){
                temp+= s[i];
            }
            else{
                reverse(temp.begin(), temp.end());
            }
        }
        return temp;
    }
};

int main(){

    return 0;
}