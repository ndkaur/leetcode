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

class Solution { //O(n^2)
public:
    unordered_set<char> st = {'a','e','i','o','u'};
    bool isVowel(char ch){
        return st.find(ch)!=st.end();
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            int vow = 0;
            int con =0;
            for(int j=i; j<n; j++){
                isVowel(s[j]) ? vow++ : con++;
                // check condition vow *con %k ==0
                if(vow==con && (vow*con)%k==0)
                    cnt++;
            }
        }
        return cnt;
    }
};



int main(){

    return 0;
}