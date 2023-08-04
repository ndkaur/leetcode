/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
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
        Node* currParent=root;
        Node* baseChild;
        Node* currChild;
        Node* nextChild;
        while(currParent){
            //  when currParent doesnot have any child mostly the leaf nodes
            while(currParent->next && !currParent->left && !currParent->right)
                currParent= currParent->next;
            //  giving val to children
            currChild = baseChild = currParent->left ? currParent->left : currParent->right;

            while(currChild){
                // making the link of curr left with curr right 
                // right node exist and check if it is actually the left node and not right one
                if(currParent->right && currChild != currParent->right)
                    nextChild = currParent->right;
                else{ //curchild = parent->right beacuse maybe parent->left doesnot exist
                    currParent= currParent->next; // connect with the next nodes that are present
                    
                    while(currParent && !currParent->left && !currParent->right) // checking if it is the leaf node of next side
                        currParent= currParent->next; 
                    // setting nextchild to be left or right otherwise null
                    nextChild = currParent ? currParent->left ? currParent->left : currParent->right : currParent;
                }

                //  make the connection 
                currChild->next= nextChild;
                currChild= nextChild;
            }
            // move the curr parent ahead 
            currParent= baseChild;
        }
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz= q.size();
            for(int i=0;i<sz;i++){
                Node* curr= q.front();
                if(sz-1==i) // means at the last node od=f a level and next must be null
                    curr->next= NULL;
                q.pop();
                if(sz-1!=i) // means if node is not the last node of the level , connect with next node 
                    curr->next= q.front();

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return root;
    }
};
// @lc code=end


int main(){

    return 0;
}