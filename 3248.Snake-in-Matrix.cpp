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
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int sz = commands.size();
        int ptr = 0;
        pair<int,int> ans = {0,0};
        for(int ptr=0; ptr<sz; ptr++){
           if(commands[ptr]=="UP"){ // i,j => i-1,j
                ans = {ans.first-1, ans.second};
            }
            else if(commands[ptr]=="RIGHT"){ // i,j => i,j+1
                ans = {ans.first, ans.second+1};
            }
            else if(commands[ptr]=="DOWN"){ // i,j =>i+1,j
                ans = {ans.first+1, ans.second};
            }
            else{ // "LEFT" i,j => i, j-1
                ans = {ans.first, ans.second-1};
            }
        }
        return ans.first*n+ ans.second;
    }
};

int main(){

    return 0;
}