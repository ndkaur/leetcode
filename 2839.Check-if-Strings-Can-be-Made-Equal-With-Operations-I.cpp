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


class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string temp1 = s1;
        swap(temp1[0], temp1[2]);
        string temp2 = temp1;
        swap(temp2[1], temp2[3]);
        string temp3 = s1;
        swap(temp3[1], temp3[3]);
        return (s1==s2 || temp1==s2 || temp2==s2 || temp3==s2);
    }
};

int main(){

    return 0;
}