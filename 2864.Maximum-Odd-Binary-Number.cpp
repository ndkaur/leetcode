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
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int cnt =0;
        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i]=='1')
                cnt++;
            ans+= '0';
        }
        // put 1 in the staring and save 1 to add at the end 
        for(int i=0; i<cnt-1; i++){
            ans[i] ='1';
        }
        ans[n-1]= '1';
        return ans;
    }
};

int main(){

    return 0;
}