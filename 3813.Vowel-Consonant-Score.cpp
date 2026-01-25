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
    int vowelConsonantScore(string s) {
        int n = s.size();
        int ans = 0;
        int v = 0;
        int c = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u'){
                v++;
            }
            else if(isalpha(s[i]))
                c++;
        }
        if(c>0)
            ans = floor(v/c);
        else 
            ans = 0;
        return ans;
    }
};


int main(){

    return 0;
}