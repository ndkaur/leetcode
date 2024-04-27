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
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]] = i;
        }

        vector<int> ans;
        int prev = -1;
        int mx = 0;
        for(int i=0; i<n; i++){
            mx = max(mx, mp[s[i]]);
            if(mx==i){
                ans.push_back(mx-prev);
                prev = mx;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}