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
        int countOfSubstrings(string s, int k) {
            int n = s.size();
            set<char> vowel = {'a','e','i','o','u'};
            int cnt = 0;
            for(int i=0; i<n; i++){
                set<char> st;
                int consonant = 0;
                for(int j=i; j<n; j++){
                    if(vowel.find(s[j])!=vowel.end()){ // its a vowel
                        st.insert(s[j]);
                    }
                    else{
                        consonant++;
                    }
    
                    if(st.size()==5 && consonant==k){
                        cnt++;
                    }
                }
            }
            return cnt;
        }
    };


int main(){

    return 0;
}