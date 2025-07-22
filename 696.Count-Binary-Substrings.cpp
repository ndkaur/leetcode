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
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans=0;
        int cnt = 1;
        vector<int> group;
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else{
                group.push_back(cnt);
                cnt=1;
            }
        }
        group.push_back(cnt);
        for(int i=1; i<group.size(); i++){
            ans += min(group[i], group[i-1]);
        }
        return ans;
    }
};

// "00110011"
// 2, 2, 2, 2
// ans = 2 + 2 + 2 =6

// "10101" 
// 1 1 1 1 1
// ans = 1+1+1+1



int main(){

    return 0;
}