/*
 * @lc app=leetcode id=2049 lang=cpp
 *
 * [2049] Count Nodes With the Highest Score
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
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    struct Node{
        Node* left;
        Node* right;
        int val;
        long long count; // to count the size of nodes till that node
        Node(int c){
            left=NULL;
            right=NULL;
            count=0;
            val=c;
        }
    };

    vector<long long> ans;

    int postorder(Node* root, int n){
        if(!root) 
            return 0;
        int left= postorder(root->left,n);
        int right= postorder(root->right,n);
        root->count= left+right;

        //  made left1 right 1 because at leaf nodes the left and right child=0 when find product it will be 0*0* val leads to whole zero
        long long left1= left;
        long long right1= right;

        if(left1==0)
            left1=1;
        if(rigth1==0)
            right1=1;
        //  val is the size of the remaining subtree which is the link with the parent 
        //  val is the size of the subtree formed on the parent side except left and right root 
        long long val= (n-left-right-1);
        if(val==0) // val will be 0 in case of top root node of tree as there is no subtree remaining on the parent side
            val=1;
        //  ans is product of size of all subtrees 
        ans.push_back(left1*right1*val);
        return  root->count+1; // return count+1 to above parent node // ie the size till that node + its own size
    }

    int countHighestScoreNodes(vector<int>& parents) {
        ans.clear();
        int n= parents.size();
        //  making a tree from parent array
        vector<Node*> tree(n);
        for(int i=0;i<n;i++){
            tree[i]= new Node(i);
        }

        for(int i=0;i<n;i++){
            if(parent[i]!=-1){
                if(tree[parent[i]]->left==NULL){ // if no left child then attach left child
                    tree[parent[i]]->left= tree[i];
                }
                else
                    tree[parent[i]]->right= tree[i];
            }
        }

        Node* root= tree[0];
        postorder(root,n);
        int c=0;
        //  find the max products from the ans array 
        sort(ans.rbegin(), ans.rend());
        for(int i=0;i<n;i++){
            if(ans[i]==ans[0]) // count itself also 
                c++;
            else 
                break;
        }
        return c;
    }
};
// @lc code=end


int main(){

    return 0;
}