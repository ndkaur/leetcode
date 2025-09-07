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


class Solution0 {
public:
    int minOperations(string s) {
        int n = s.size();
        set<char> st(s.begin(), s.end());
        for(auto ch:st){
            if(ch=='a' && st.size()==1)
                return 0;
        }

        char mn = 'z';
        for(const auto& ch:s){
            if(ch=='a')
                continue;
            mn = min(mn,ch);
        }
        
        return 'z'-mn+1;
    }
};

// minimum no of operations depend ont he minimum char , cause it will take max opertaion to make it to z then to a
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        for(int i=0; i<n; i++){
            int ch = s[i]-'a';
            freq[ch]++;
        }

        //  now convert the char directly to a 
        for(int i=1; i<26; i++){
            // i==1 cause a is at idx=0, we skip a
            // z= 25, a=26
            if(freq[i]!=0) // the first minimum chr that we came acroos 
                return (26-i);
        }
        return 0;
    }
};

int main(){

    return 0;
}