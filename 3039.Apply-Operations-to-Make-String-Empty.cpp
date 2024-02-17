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
    string lastNonEmptyString(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        for(auto ch:s){
            freq[ch-'a']++;
        }
        int mx =0;
        for(int f:freq){
            mx = max(mx,f);
        }
        string ans ="";
        for(int i=n-1; i>=0; i--){
            char ch = s[i];
            if(freq[ch-'a']==mx){
                freq[ch-'a'] = -1;
                ans = ch+ans;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}