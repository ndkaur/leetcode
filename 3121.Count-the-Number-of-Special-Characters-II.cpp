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
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int cnt = 0;
        vector<int> up(150,-1);
        vector<int> low(150, -1);
        for(int i=0; i<n; i++){
            if(isupper(word[i])){ // storing the first occurence of char
                if(up[word[i]]==-1){
                    up[word[i]]=i;
                }
            }
            else{ // its a lowercase letter , store its last occurence 
                low[word[i]]=i;
            }
        }

        // for(auto i:up){
        //     cout<<i<<" ";
        // }
        
        // 65=A, 97=a.. so dif = 97-65 = 32
        for(int i=0; i<up.size(); i++){
            // upper char doent exist and lower also doent exist 
            // if upper is i , then lower in other aray will be same idx +32
            if(up[i]==-1 || low[i+32]==-1)
                continue;
            if(low[i+32]<up[i]){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}