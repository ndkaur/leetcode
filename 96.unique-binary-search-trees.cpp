/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> A(n+1);
        A[0]=A[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                A[i]+= A[j-1]*A[i-j];
            }
        }
        return A[n];
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n =3;
    int ans=sol.numTrees(n);
    cout<<ans;
    return 0;
}