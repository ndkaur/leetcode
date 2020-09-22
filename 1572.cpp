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
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat.size();
        for(int i=0;i<mat.size();i++){
            sum+= mat[i][i];
        }
        for(int i=0;i<mat.size();i++){
            sum+=mat[i][n-1-i];
        }
        
        if(n%2!=0) {
            sum=sum-mat[n/2][n/2];
        }
        
        return sum;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    int sum=sol.diagonalSum(mat);
    cout<<sum;
    return 0;
}