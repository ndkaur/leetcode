/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root || !root->left) return root;
        root->left->next= root->right;
        if(root->next){
            root->right->next= root->next->left;
        }
        root->left= connect(root->left);
        root->right = connect(root->right);
        return root;
    }
};


class Solution {
public:
    Node* connect(Node* root) {
        Node* temp =root; // ptr moves only on the startinf most left ptrs 
        while(temp!=NULL && temp->left!=NULL){
            Node* n= temp; // standing on previous level do work for next level
            while(true){
                n->left->next = n->right;
                if(n->next== NULL) break;
                n->right->next= n->next->left;
                n= n->next;
            }
            temp = temp->left; 
        }
        return root;
    }
};
// @lc code=end


int main(){

    return 0;
}