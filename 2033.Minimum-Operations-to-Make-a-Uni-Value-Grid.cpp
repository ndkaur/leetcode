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
        int minOperations(vector<vector<int>>& grid, int x) {
            int n = grid.size();
            vector<int> val;
            int rem = grid[0][0]%x;
    
            for(auto g:grid){
                for(int v:g){
                    if(v%x!=rem)
                        return -1;
                    val.push_back(v);
                }
            }
    
            sort(val.begin(), val.end());
            int median = val.size()/2;
            int steps = 0;
            for(int i=0; i<val.size(); i++){
                steps  += abs(val[i]-val[median])/x;
            }
            return steps;
        }
    };
    
    // emt diff < x

int main(){

    return 0;
}