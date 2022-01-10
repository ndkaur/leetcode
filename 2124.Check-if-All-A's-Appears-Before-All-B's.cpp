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
    bool checkString(string s) {
        int n= s.size(); 
        for(int i=0;i<n;i++){
              if(s[i]=='b'){
                    while(i<n){
                          if(s[i]=='a')
                              return false;
                        i++;
                    }
              }
        }
        return true;
    }
};

int main(){
      Solution sol;
      string s="bbb";
      bool ans = sol.checkString(s);
      cout<<ans;
   return 0;
}