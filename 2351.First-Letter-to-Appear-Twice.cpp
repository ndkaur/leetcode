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
    char repeatedCharacter(string s) {
        int n= s.size();
        map<char,int> mp;
        char ans;
        for(auto ch:s){
            if(mp.find(ch)!=mp.end()){
                ans=ch;
                break;
            }
            mp[ch]++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s= "abccbaacz";
    char ans = sol.repeatedCharacter(s);
    cout<<ans;
    return 0;
}