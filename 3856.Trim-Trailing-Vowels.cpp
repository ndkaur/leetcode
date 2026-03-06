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
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }
    string trimTrailingVowels(string s) {
        int n = s.size();
        int idx = n-1;
        for(int i=n-1; i>=0; i--){
            if(isVowel(s[i])){
                idx--;
            }
            else 
                break;
        }
        return s.substr(0, idx+1);
    }
};


int main(){

    return 0;
}