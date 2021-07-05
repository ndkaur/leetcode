#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
    vector<int> grayCode(int n) {
        vector<int> list;
        list.push_back(0);
        if(n==0)    return list;
        list.push_back(1);
        int curr=1;
        for(int i=2;i<=n;i++){
            curr=curr*2;
            for(int j=list.size()-1;j>=0;j--){
                list.push_back(curr+list[j]);
            }
        }
        return list;
    }
};


int main(){
    Solution sol;
    int n =1;
    vector<int> ans= sol.grayCode(n);
    print(ans);
    return 0;
}