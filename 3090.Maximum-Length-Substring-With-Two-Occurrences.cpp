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
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        map<char,int> mp;
        int mx = 0;

        while(r<n){
            mp[s[r]]++;
           
            while(l<r && mp[s[r]]>2){
                mp[s[l]]--;
                l++;
            }
            mx = max(mx, r-l+1);
            r++;
        }
        return mx;
    }
};


int main(){

    return 0;
}