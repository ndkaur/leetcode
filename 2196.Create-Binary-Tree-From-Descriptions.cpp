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

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        int n = des.size();
        // map to store val -> treenode  for both parent and child
        unordered_map<int, TreeNode*> mp;
        // map used to find the root node 
        unordered_map<int,bool> find;
        // root node will be that node which is not child of anyone 
        for(auto d:des){
            // check count of parent node
            if(mp.count(d[0])==0){
                TreeNode* parent = new TreeNode(d[0]);
                mp[d[0]]= parent; // int->treenode
            }
            // check count of child node
            if(mp.count(d[1])==0){
                TreeNode* child = new TreeNode(d[1]);
                mp[d[1]] = child;
            }
            // now check if left child or right 
            if(d[2]==1){ // left child
                // node at d[0] parent ->left = node at d[1] child
                mp[d[0]]->left = mp[d[1]];
            }
            else{ // right child
                mp[d[0]]->right = mp[d[1]];
            }
            // now keep count of child nodes to find who is the main root node
            find[d[1]] = true;
        }
        TreeNode* root = NULL;
        //the root which is not child of anyone is the parent node 
        for(auto d:des){
            // check parent in child map if false then its root
            if(find[d[0]]== false){
                root = mp[d[0]]; // tree attached to that node 
                break;
            }
        }
        return root;
    }
};


int main(){

    return 0;
}