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
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        int n = variables.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];

            // x = a^b % 10 
            int x = 1;
            for(int i=0; i<b; i++){
                x = (x*a) % 10;
            }

            // x^c % m 
            int y = 1;
            for(int i=0; i<c; i++){
                y = (x*y)%m;
            }

            if(y==target)
                ans.push_back(i);
        }
        return ans;
    }
};


int main(){

    return 0;
}