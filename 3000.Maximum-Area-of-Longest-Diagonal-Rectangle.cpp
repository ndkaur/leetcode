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
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        int n = dim.size();

        double mx = INT_MIN;
        int area = 0;

        for(int i=0; i<n; i++){
            double diag = sqrt(dim[i][0]*dim[i][0] + dim[i][1]*dim[i][1]);
            
            if(mx<=diag){
                if(mx==diag){
                    area = max(area, dim[i][0]*dim[i][1]);
                }
                else 
                    area = dim[i][0]*dim[i][1];
                mx = diag;
            }
        }
        return area;
    }
};

// 9 3   3 4
// 8 6   4 3 


int main(){

    return 0;
}