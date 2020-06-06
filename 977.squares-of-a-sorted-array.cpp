/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
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
    vector<int> sortedSquares(vector<int>& A) {
        int len =A.size();
        vi out;
        for(int i=0;i<len;i++){
           int sq=A[i]*A[i];
           out.push_back(sq);
        }
        sort(out);
        return out;
    }

    void sort(vi &A){
        int len = A.size();
        for(int i=0; i<len-1; i++){
            for(int j=0;j<len-i-1;j++){
               if(A[j]>A[j+1])
                 swap(A[j],A[j+1]);
            }
        }
    }
};
// @lc code=end
int main(){
    Solution sol;
    vi out,A;
    int i,j;
    A={-4,-1,0,3,10};
    out=sol.sortedSquares(A);
    print(out);

    return 0;
}