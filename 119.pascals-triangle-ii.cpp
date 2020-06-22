/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    vector<int> getRow(int ri) {
        vector<vector<int>> pascal(ri+1,vector<int>(ri+1));
        
        pascal[0][0]=1;
        for(int i=1;i<=ri;i++){
            pascal[i][0]=pascal[i][i]=1;
            for(int j=1;j<ri;j++){
                pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
            }
        }
        return pascal[ri];

    }
};
// @lc code=end


int main(){
    Solution sol;
    
    int ri=33;
    vector<int> out;
    out=sol.getRow(ri);
    print(out);
    return 0;
}



