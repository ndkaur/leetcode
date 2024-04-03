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
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        for(int i=0; i<n; i++){
            if(possible[i]==0){
                possible[i] = -1;
            }
        }
        int sum = 0;
        for(int p:possible){
            sum+=p;
        }
        
        int curr = 0; // dan sum 
        for(int i=0; i<n-1; i++){
            curr += possible[i];
            // bob sum = remining 
            // remaining < dan sum , so all next array will also give greater
            if(sum-curr<curr)
                return i+1;
        }
        return -1;
    }
};

int main(){

    return 0;
}