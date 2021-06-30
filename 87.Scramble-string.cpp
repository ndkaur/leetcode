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

class Solution0 {
public:
    bool isScramble(string s1, string s2) {
        int n= s1.size();
        if(s1==s2) return true;
        int count[26]={0};
        for(int i=0;i<n;i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(count[i]!=0)
                return false;
        }
        for(int i=1;i<=n-1;i++){
            if (isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))
                    return true; // already same 
            if(isScramble(s1.substr(0,i), s2.substr(n-1)) && isScramble(s1.substr(i),s2.substr(0,n-i)))
                return true;
        }
        return false;
    }
}; // time limit exceeded

class Solution {
public:
    unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if(s2.size()!=n)
            return false;
        if(s1==s2)
         return true;   
        if(n==1)
            return false;
        string key = s1+" "+s2;
        if(mp.find(key)!=mp.end())
            return mp[key];
        for(int i=1;i<n;i++){
            bool withoutswap = (
                isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)));
            if(withoutswap)
                return true;
            bool withswap = (isScramble(s1.substr(0,i),s2.substr(n-i)) &&isScramble(s1.substr(i),s2.substr(0,n-i)) );
            if(withswap)
                return true;
        }
        return mp[key] = false;
    }
};

int main(){
    Solution sol;
    string s1="abcde";
    string s2= "caebd";
    bool ans= sol.isScramble(s1,s2);
    cout<<ans;
    return 0;
}