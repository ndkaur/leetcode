#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
    int numberOfMatches(int n) {
        int match=0;
        if(!n)
            return 0;
        while(n>1){
            if(n%2==0){
                match+=n/2;
                n=n/2;
            }
            if(n%2!=0){
                match+=(n-1)/2;
                n=(n-1)/2+1;
            }
        }
        return match;
    }
};

class Solution {
public:
    int numberOfMatches(int n) {
        int match=0;
        if(!n)
            return 0;
        while(n>1){
            match+=n/2;
            n=(n+1)/2;
        }
        return match;
    }
};

int main(){
    Solution sol;
    int n =7;
    int match =sol.numberOfMatches(n);
    cout<<match;
    return 0;
}