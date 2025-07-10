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
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        while(l<r){
            if(s[l]!=s[r]){
                if(s[l]-'a'<s[r]-'a'){
                    s[r]= s[l];
                }
                else{
                    s[l] = s[r];
                }
            }
            l++;
            r--;
        }
        return s;
    }
};


int main(){

    return 0;
}