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
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> dec(n,0);
        
        int cnt=1;

        dec[0]=1;
        for(int i=1; i<n; i++){
            if(security[i-1]>=security[i])
                cnt++;
            else 
                cnt=1;
            dec[i]=cnt;
        }

        for(auto d:dec){
            cout<<d<<" ";
        }
        cout<<endl;
        
        vector<int> inc(n,0);
        inc[n-1] =1;
        cnt=1;
        for(int i=n-2; i>=0; i--){
            if(security[i]<=security[i+1]){
                cnt++;
            }
            else 
                cnt=1;
            inc[i]=cnt;
        }
        
        for(auto i:inc){
            cout<<i<<" ";
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(dec[i]-1>=time && inc[i]-1>=time)
                ans.push_back(i);
        }
        return ans;
    }
};

int main(){

    return 0;
}