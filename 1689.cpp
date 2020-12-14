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
    int minPartitions(string n) {
        int ans= *max_element(n.begin(),n.end());
        return ans-'0';
    }
    
};

int main(){
    Solution sol;
    string n="7895346";
    int ans=sol.minPartitions(n);
    cout<<ans;
    return 0;
}