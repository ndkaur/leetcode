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
    char repeatedCharacter(string s) {
        int n= s.size();
        map<char,int> mp;
        char ans;
        for(auto ch:s){
            if(mp.find(ch)!=mp.end()){
                ans=ch;
                break;
            }
            mp[ch]++;
        }
        return ans;
    }
};



// using bit masking
class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.size();
        int appear = 0;
        int mask = 0;

        for(int i=0; i<n; i++){
            mask = 1<<(s[i]-'a');
            if((mask & appear)!=0){ // same value bit and return 1 so that means that char already existed earlier
                return s[i];
            }
            appear = appear|mask;
        }
        return 0;
    }
};

// abcc
// appear = 0
// mask = 1<<(a-a)= 1<<0 = 1 
// 0 & 1 = 0 

// appear = 1
// mask = 1<<(b-a)= 1<<1 = 10 
// 1 & 10 = 0

// appear = 11 
// mask = 1<<(c-a) = 1<<2 = 100
// 11 & 100 = 0 

//appear = 111 
// mask = 1<<(c-a) = 1<<2 = 100
// 111 & 100 = 100 
//return c 



int main(){
    Solution sol;
    string s= "abccbaacz";
    char ans = sol.repeatedCharacter(s);
    cout<<ans;
    return 0;
}