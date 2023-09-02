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

class Solution0 {
public:
    bool checkStrings(string s1, string s2) {
        int n= s1.size();
        map<char,int> mp1even;
        map<char,int> mp1odd;
        map<char,int> mp2even;
        map<char,int> mp2odd;
        
        for(int i=0; i<n; i++){
            if(i%2==0){
                mp1even[s1[i]]++;
                mp2even[s2[i]]++;
            }
            else{
                mp1odd[s1[i]]++;
                mp2odd[s2[i]]++;
            }
        }
        return (mp1even==mp2even && mp1odd==mp2odd);
    }
};



int main(){

    return 0;
}