/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
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
    vector<int> sortArrayByParity(vector<int>& A) {
        int len =A.size();
        vector<int> output;
        for(int i=0;i<len;i++){
            if(A[i]%2==0)
              output.push_back(A[i]);
              
        }
        for(int i=0;i<len;i++){
            if(A[i]%2!=0)
              output.push_back(A[i]);
              
        }
        return output;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vi A,output;
    int i;
    A={4,1,3,2};
    output=sol.sortArrayByParity(A);
    print(output);
    // return 0;
}