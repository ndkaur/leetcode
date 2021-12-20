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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

class Solution {
public:
    string addSpaces(string s, vector<int>& sp) {
        int n= s.size();
        int m= sp.size();
        int j=0;
        string ans;
        for(int i=0;i<n;i++){
            if(j<m && i==sp[j]){
                ans+= ' ';
                j++;
            }
            ans+= s[i];
        }
        return ans;
    }
};

int main(){
      Solution sol;
      string s="LeetcodeHelpsMeLearn";
      vector<int> sp={8,13,15};
      string ans = sol.addSpaces(s,sp);
      for(auto s:ans)
            cout<<s;
      return 0;
}