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
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        int n= ast.size();
        sort(ast.begin(),ast.end());
        long long m= mass;
        for(int i=0;i<n;i++){
              if(ast[i]<=m)
                  m+=ast[i];
              else 
                  return false;
        }
        return true;
    }
};

int main(){
      Solution sol;
      int mass= 5;
      vector<int> ast={4,9,23,4};
      int ans = sol.asteroidsDestroyed(mass, ast);
      cout<<ans;
   return 0;
}