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
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root)
            return -1;

        vector<long long> sums;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            long long sum =0;
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto node= q.front();
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                sum += node->val;
            }
            sums.push_back(sum);
        }
        sort(sums.begin(), sums.end(), greater<long long>());
        // 5, 10 , 13 , 17 
        int n = sums.size();
        if(n < k)
            return -1;
        return sums[k-1];
    }
};

int main(){

    return 0;
}