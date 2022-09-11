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


// approach similar to longest substring without repeating characters
// make a set when any repeating char comes up claer the set increase the count add the ele again

class Solution {
public:
    int partitionString(string s) {
        int n= s.size();
        int cnt=1;
        set<char> st;

        for(int i=0; i<n; i++){
            if(st.find(s[i])== st.end()){
                st.insert(s[i]);
            }
            else{
                cnt++;
                st.clear();
                st.insert(s[i]);
            }
        }
        return cnt;
    }
};


int main(){

    return 0;
}