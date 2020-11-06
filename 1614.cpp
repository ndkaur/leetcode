#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int res=0;
        int cur=0;
        for(char c :s){
            if(c== '('){
                cur++;
                res=max(res,cur);
            }
            if(c == ')')
                cur--;
        } 
        return res;
    }
};

int main(){
    Solution sol;
    string s="1+(2*3)/(2-1)";
    int ans=sol.maxDepth(s);
    cout<<ans;
    return 0;
}