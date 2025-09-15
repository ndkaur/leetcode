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
    bool isVowel(char& ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        return false;
    }
    bool doesAliceWin(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(isVowel(s[i]))
                cnt++;
        }

        if(cnt>0)
            return true;
        return false;
    }
};



class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.size();
        
        for(int i=0; i<n; i++){
            int ch = s[i];
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                return true;
        }

        return false;
    }
};

// cnt no of vlowels in whole string cnt
// cnt is odd -> pick whole string , aloce win 
// cnt is even -> pick cnt-1 , let 1 vowel remain , bob will pick 0 even , then alice pick and alice win 

// so if it has any cnt alie win , if no vowel cnt bob win 

int main(){

    return 0;
}