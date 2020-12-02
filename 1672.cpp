#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
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
    int maximumWealth(vector<vector<int>>& accounts) {
        int m =accounts.size();
        int n=accounts[0].size();
        int mwealth=0;
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum= sum+accounts[i][j];
            }
            mwealth=max(mwealth,sum);
        }
        return mwealth;
    }
};

int main(){
    
    return 0;
}