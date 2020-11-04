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
    int maxPower(string s) {
        int n=s.length();
        int count=0;
        char previous = ' ';
        int mxcount=0;
        for(int i=0;i<n;i++){
            char c = s.at(i);
            if(c==previous)
                count++;
            else {
                count=1;
                previous =c;
            }
            mxcount =max(mxcount , count);
        }
        return mxcount;
    }
};

int main(){
    Solution sol;
    string s="leetcode";
    int ans=sol.maxPower(s);
    cout<<ans;
    return 0;
}