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

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        // left right root post order
        int cnt =0;
        dfs(root,cnt);
        return cnt;
    }
    pair<int,int> dfs(TreeNode* root,int& cnt){
        if(!root) return {0,0}; // sum, no of nodes
        auto left = dfs(root->left,cnt);
        auto right = dfs(root->right ,cnt);
        int sum = left.first + right.first + root->val;
        int number = left.second + right.second + 1; // current node = 1
        if(sum/number == root->val)
            cnt++;
        return {sum,number};
    }
};

int main(){

    return 0;
}

