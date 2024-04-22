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
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int cnt = 0;
        set<char> st;
        for(auto ch:word){
            st.insert(ch);
        }
        for(auto itr:st){
            if(isupper(itr) && st.find(tolower(itr))!=st.end())
                cnt++;
        }
        return cnt;
    }
};

int main(){

    return 0;
}