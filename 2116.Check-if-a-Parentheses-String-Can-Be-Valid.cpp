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
    bool canBeValid(string s, string locked) {
        int n= s.size();
        if(n%2==1) return false;
        int total=0, open=0,close=0;
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0')
                total+=1;
            else if(s[i]=='(')
                open+=1;
            else if(s[i]==')')
                close+=1;
            if(total-open+close<0) return false;
        }
        total=open=close=0;
        for(int i=0;i<n;i++){
            if(locked[i]=='0')
                total+=1;
            else if(s[i]=='(')
                open+=1;
            else if (s[i]==')')
                close+=1;
            if(total+open -close<0) return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s=")(()))";
    string locked="010100";
    bool ans = sol.canBeValid(s,locked);
    cout<<ans;
   return 0;
}