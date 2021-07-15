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
    string customSortString(string order, string str) {
        int n= order.size();
        int m= str.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
            mp[order[i]]=i+1;
        sort(str.begin(),str.end(),[&](char a, char b){return mp[a]<mp[b]; });
        return str;
    }
};


int main(){
    Solution sol;
    string order="cba";
    string str= "abcd";
    string ans = sol.customSortString(order,str);
    for(auto i:ans)
        cout<<i;
    return 0;
}