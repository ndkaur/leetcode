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

// time complexity -> constant O(N)
class Solution {
public:
    bool check(string& temp, set<char>& st){
        for(int i=0; i<temp.size(); i++){
            if(st.find(temp[i])!=st.end())
                return false;
        }
        return true;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size();
        set<char> st;
        for(auto ch:brokenLetters){
            st.insert(ch);
        }
        stringstream ss(text);
        string temp;
        int cnt =0;
        while(ss>>temp){
            if(check(temp,st)){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}