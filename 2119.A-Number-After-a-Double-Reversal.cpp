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
    bool isSameAfterReversals(int num) {
      return num==0 || num%10>0;  
    }
};

int main(){
      Solution sol;
      int n= 526;
      bool ans = sol.isSameAfterReversals(n);
      return ans;
   return 0;
}