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

class Solution { // O(m*n)  space O(1)
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        for(auto row:mat){
            int n = row.size();
            for(int i=0; i<n; i++){
                if(row[i]!= row[(i+k)%n])
                    return false;
            }
        }
        return true;
    }
};

int main(){

    return 0;
}