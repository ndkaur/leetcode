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
    int maxOperations(string s) {
        int n = s.size();
        int cnt = 0;
        int pref = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                if(i==n-1 || s[i+1]=='1'){
                    cnt+=pref;
                }
            }
            else{// its a 1
                pref++;
            }
        }
        return cnt;
    }
};

// 1010101
// pref =3    cnt = 1+2+3 =6
// cnt the ones till curr idx, when we found zero then check 1 next to it 
// if at the last idx we found 0 but not 1 , then add all prefix 
// 1010101
// 0110101
// 0110011
// 0100111
// 0001111

int main(){

    return 0;
}