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
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int ans = 0;
        int prev = 0;
        int curr = 0;
        for(auto s:bank){
            curr = 0;
            for(int i=0; i<s.size(); i++){
                if(s[i]=='1')
                    curr++;
            }
            if(curr){
                ans += prev*curr;
                prev = curr;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n= bank.size();
        int m= bank[0].size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<m;j++){
                  if(bank[i][j]=='1')
                        c++;
            }
            if(c){
                  temp.push_back(c);
            }
        }
        int ans=0;
        for(int i=1;i<temp.size();i++){
              ans+= temp[i]*temp[i-1];
        }
      return ans;
    }
};

int main(){
      Solution sol;
      vector<string> bank ={"0"};
      int ans = sol.numberOfBeams(bank);
      cout<<ans;
   return 0;
}