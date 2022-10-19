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
    bool isIsomorphic(string s, string t) {
        // size equal and if char repeat then the no of repeat must be same 
        char mp_s[128]={0};
        char mp_t[128]={0};
        int n= s.size();
        for(int i=0;i<n;i++){
            if(mp_s[s[i]]!=mp_t[t[i]])
                return false; // if the no of occurence of letter is not same 
            mp_s[s[i]] =i+1;
            mp_t[t[i]]=i+1;
        }
        return true;
    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1;
        unordered_map<char, char> mp2;
        for(int i=0; i<s.size(); i++){
            mp1[s[i]] = i+1;
            mp2[t[i]] = i+1;
        }
        for(int i=0; i<s.size(); i++){
            if(mp1[s[i]] != mp2[t[i]])
                return false;
        }
        return true;
    }
};

// f b
// 1 1
// o a
// 2 2
// o r 
// 3 3  so finally  f= 1  o =3   and b =1 a=2 r=3  
// so compare f = b =1 
// o =3 a =2  so false

int main(){
    Solution sol;
    string s="foo";
    string t="bar";
    bool ans= sol.isIsomorphic(s,t);
    cout<<ans;
    return 0;
}