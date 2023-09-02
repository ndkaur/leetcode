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
    bool canBeEqual(string s1, string s2) {
         // s1 = "abcd", s2 = "cdab"
        // s1 = "abcd", s2 = "dacb"
        int n= s1.size();
       for(int i=0; i<n-2; i++){
           if(s1[i]!=s2[i]){
               swap(s1[i], s1[i+2]);
           }
       }
        return s1==s2;
    }
};

int main(){

    return 0;
}