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
    bool isAcronym(vector<string>& words, string s) {
        // ["alice","bob","charlie"], s = "abc"
        // ["never","gonna","give","up","on","you"], s = "ngguoy"
        int n = words.size();
        string temp;
        for(auto word:words){
            char c = word[0];
           
            temp += c;
        }
        for(auto ch:temp)
            cout<<ch;
        return temp==s;
    }
}; 

int main(){

    return 0;
}