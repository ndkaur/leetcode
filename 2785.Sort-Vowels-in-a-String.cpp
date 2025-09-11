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


class Solution { // nlogv -> n= lenght of string, v= no of vowels
public:
    bool isVowel(char ch){
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        return false;
    }
    string sortVowels(string s) {
        int n = s.size();
        vector<char> vow;
        for(int i=0;i<n; i++){
            if(isVowel(s[i])){
                vow.push_back(s[i]);
            }
        }
        sort(vow.begin(), vow.end());
        int idx =0;
        for(int i=0; i<n; i++){
            if(isVowel(s[i])){
                s[i]=vow[idx];
                idx++;
            }
        }
        return s;
    }
};

int main(){

    return 0;
}