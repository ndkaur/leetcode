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
    string clearStars(string s) {
        int n = s.size();
        vector<vector<int>> idx(26);
        priority_queue<char, vector<char>, greater<char>> pq;
        // pq will be storing the unique chars that comes first time 
        // and when we get * we need to remove the last char that we visitd before *
        // and that last char will be the top most char present in stack 
        // and we need to to check our map for its last occurence 
        // and at that index remove it and mark that char with !
        for(int i=0; i<n; i++){
            if(s[i]=='*'){
                // rmove its left char 
                char ch = pq.top();
                s[idx[ch-'a'].back()]='!';
                idx[ch-'a'].pop_back();
                if(idx[ch-'a'].empty())
                    pq.pop();
            }
            else{
                // char occuring for the first time 
                if(idx[s[i]-'a'].empty())
                    pq.push(s[i]);
                // adding the index of the current char
                idx[s[i]-'a'].push_back(i);
            }
        }
        string ans;
        for(char ch:s){
            // char to be removed is marked with !
            if(ch>='a')
                ans+=ch;
        }
        return ans;
    }
};

// aaba*
// pq-> a b
// 0->0,1,3
// 1->2

// ch = a 
// s= aab!*
//0->0,1


int main(){

    return 0;
}