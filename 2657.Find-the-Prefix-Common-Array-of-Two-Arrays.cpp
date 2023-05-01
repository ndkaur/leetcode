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
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n= A.size();
        int  m= B.size();
        vector<int> ans(n,0);
        map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[A[i]]++;
            mp[B[i]]++;
            int cnt =0;
            for(auto itr:mp){
                if(itr.second >=2){
                    cnt++;
                    ans[i] = cnt;
                }
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}