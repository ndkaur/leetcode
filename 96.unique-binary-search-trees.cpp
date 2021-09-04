/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */
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
// #include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution0 {
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

// catalan numbers :- 1,1,2,5,14,42,132,429,1430,

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int left=0;left<i;left++){
                int right = i-left-1;
                dp[i]+= dp[left]*dp[right];
            }
        }
        return dp[n];
    }
};

// class Solution1 {  // time limit exceeded
// public:
//     int numTrees(int n) {
//         auto res = generate(1,n);
//         return res.size();
//     }
//     vector<TreeNode*> generate(int start,int end){
//         vector<TreeNode*> ans;
//         if(end-start<0)  ans.push_back(0);
//         if(end-start==0) ans.push_back(new TreeNode(start));
//         if(end-start>0){
//             for(int i=start;i<=end;i++){
//                 vector<TreeNode*> l=generate(start,i-1);
//                 vector<TreeNode*> r=generate(i+1,end);
//                 for(int j=0;j<l.size();j++){
//                     for(int k=0;k<r.size();k++){
//                         TreeNode* extra= new TreeNode(i);
//                         extra->left= l[j];
//                         extra->right = r[k];
//                         ans.push_back(extra);
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };



// @lc code=end


int main(){
    Solution sol;
    int n =3;
    int ans= sol.numTrees(n);
    cout<<ans;
    return 0;
}