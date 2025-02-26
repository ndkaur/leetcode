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
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // we need to keep track of the postions as well 
        // ans if with one swap we can make strings equal then return true
        vector<int> idx;
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i]){
                idx.push_back(i);
            }

            // if more than two diffrent indexs are there , that 
            // means more than two swapes are required 
            if(idx.size()>2){
                return false;
            }
        }

        if(idx.empty()) // this means strings are already equal
            return true;
        
        if(idx.size()==2){
            swap(s1[idx[0]], s1[idx[1]]);
        }

        return s1==s2;
    }
}; 



int main(){

    return 0;
}