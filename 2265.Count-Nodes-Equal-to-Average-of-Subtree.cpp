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
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// after one iteration of dfs we need to store the current 
// sum formed and the number of nodes visited till now so to find the average 
// and we use postorder -> left right root 
// cause only after visiting left and right we can calculate the average of the nums.


class Solution0 { // O(n^2)
public:
    int averageOfSubtree(TreeNode* root) {
        if(!root) 
            return 0;
        int ans = 0;
        // requirements -> sum, cnt -> avg 
        solve(root,ans);
        return ans;
    }
    void solve(TreeNode* root, int& ans){
        if(!root) return;
        // finding avg and checking if condition satisfied 
        int cnt = 0;
        int avg = (sum(root, cnt)/cnt);
        // preorder traversal
        if(avg==root->val)
            ans++;
        solve(root->left, ans);
        solve(root->right, ans);
    }
    // main part of finding sum and cnt is done here 
    int sum(TreeNode* root, int& cnt){
        if(!root)
            return 0;
        cnt++;
        int left = sum(root->left, cnt);
        int right = sum(root->right, cnt);
        return (left+right+root->val);
    }
};


class Solution { // O(n)
public:
    int averageOfSubtree(TreeNode* root) {
        if(!root) 
            return 0;
        int ans = 0;
        // requirements -> sum, cnt -> avg 
        // recursive function here cant be void or cant return int 
        // cause we want both cnt and sum at same time so use pair
        solve(root,ans); 
        return ans;
    }
    pair<int,int> solve(TreeNode* root, int& ans){
        if(!root)
            return {0,0};
        
        auto left = solve(root->left, ans);
        auto right = solve(root->right, ans);
        int sum = left.first + right.first + root->val;
        int nodesCnt = left.second + right.second + 1;

        if(sum/nodesCnt == root->val)
            ans++;
            
        return {sum, nodesCnt};
    }
};

int main(){

    return 0;
}

