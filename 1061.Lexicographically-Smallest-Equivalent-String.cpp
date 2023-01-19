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
    int parent[26];
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        memset(parent,-1,sizeof(parent));
        for(auto i=0; i<s1.size(); i++){
            unionn(s1[i]-'a', s2[i]-'a');
        }
        for(auto i=0; i<baseStr.size(); i++){
            // subtracting -a for taking out of string , adding a to add back again in string 
            baseStr[i] =  find(baseStr[i]-'a') + 'a';
        }
        return baseStr;
    }
     
    void unionn(int x, int y){
        x = find(x);
        y = find(y);
        if(x != y){ // nobosy alredy had a parent or different parents 
            // min will be the parent 
            parent[max(x,y)] = min(x,y);
        }
    }

    int find(int x){
        if(parent[x] == -1)
            return x;
        return parent[x] = find(parent[x]);
    }
};

// s1 = "parker", s2 = "morris"

int main(){

    return 0;
}