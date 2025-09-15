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
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        return false;
    }
    int maxFreqSum(string s) {
        int n = s.size();
        map<char,int> mp1,mp2;
        for(int i=0; i<n; i++){
            int ch = s[i];
            if(isVowel(ch)){
                mp1[ch]++;
            }
            else{
                mp2[ch]++;
            }
        }
        int mxvow=0;
        for(auto ch:mp1){
            mxvow = max(mxvow, ch.second);
        }

        int mxcon =0;
        for(auto ch:mp2){
            mxcon = max(mxcon, ch.second);
        }

        return mxvow+mxcon;
    }
};


class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        vector<int> freq(26);
        int maxVowel = 0;
        int maxConso = 0;

        for (char c : s) {
            int i = c - 'a';
            freq[i]++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                maxVowel = max(maxVowel, freq[i]);
            }
            else {
                maxConso = max(maxConso, freq[i]);
            }
        }
        return maxVowel + maxConso;
    }
};

int main(){

    return 0;
}