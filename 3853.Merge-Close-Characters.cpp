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
    string mergeCharacters(string s, int k) {
        int n = s.size();
        vector<int> freq(26,-1);
        string ans = "";

        for(int i=0; i<n; i++){
            int idx = s[i]-'a';
            if(freq[idx]==-1){
                freq[idx] = ans.size();
                ans+=s[i];
            }
            else{
                if(ans.size()-freq[idx]<=k){
                    continue;
                }
                else{
                    freq[idx] = ans.size();
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}