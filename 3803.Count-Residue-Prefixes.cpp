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
    int residuePrefixes(string s) {
        int n = s.size();
        int cnt = 0;
        set<char> st;
        for(int i=0; i<n; i++){
            st.insert(s[i]);
           
            if(st.size()==(i+1)%3)
                cnt++;   
        }
        // for(auto itr:st){
        //     cout<<itr;
        // }
        return cnt;
    }
};

int main(){

    return 0;
}