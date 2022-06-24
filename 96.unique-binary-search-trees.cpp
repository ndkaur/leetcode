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

class Solution {  // time limit exceeded 
public:
    int numTrees(int n) {
        int ans=0;
        if(n==1 || n==0) 
            return 1;
        for(int i=0;i<n;i++){
            ans+= numTrees(i)* numTrees(n-i-1);
        }
        return ans;
    }
};
//  c[i] += c[i]* c[n-i-1]
// using dp
class Solution {
public:
    int numTrees(int n) {
        vector<int> ans(n+1,0);
        ans[1]= ans[0]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                ans[i]+=  ans[j]* ans[i-j-1];
            }
        }
        return ans[n];
    }
};


//  binomial cofficent  2n C n / n+1 
//  property nCr = nC n-r
class Solution {
public:
    long cal(int n , int k){
        long ans=1;
        if(k>n-k)
            k= n-k; // property
        for(int i=0;i<k;i++){
            ans*= (n-i);
            ans/= (i+1);
        }
        return ans;
    }
    int numTrees(int n) {
        return cal(2*n, n) / (n+1); 
        //  to calculate 2n C n
    }
};

// @lc code=end


int main(){
    Solution sol;
    int n =3;
    int ans= sol.numTrees(n);
    cout<<ans;
    return 0;
}