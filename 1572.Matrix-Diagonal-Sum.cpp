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
        int m= mat.size();
        int n=mat[0].size();
        double sum1=0,sum2=0;
        if(mat.size()==1) return mat[0][0];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 sum1 += mat[i][j]+mat[i+1][j+1];
            }
        }
        return sum1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                sum2+= mat[i][j]+mat[i-1][j-1];
            }
        }
    }
};


int main(){
    Solution sol;
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    int ans=sol.diagonalSum(mat);
    cout<<ans;
    return 0;
}