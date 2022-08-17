/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
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
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution { //O(n)+O(n)    O(N)
public:
    Node* copyRandomList(Node* head) {
        // iterrate first time to fill map
        map<Node* , Node*> m;
        Node* ptr= head;
        // fill map with ptr->val
        while(ptr){
            m[ptr] = new Node(ptr->val);
            ptr= ptr->next;
        }
        ptr= head;
        // second iteration for adding {val,random} to copy nodes
        while(ptr){
            m[ptr]->next= m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr= ptr->next;
        }
        return m[head];
    }
};

// solution to use O(1) space 
class Solution { //O(n)+O(n)    O(N)
public:
    Node* copyRandomList(Node* head) {
        Node* curr= head;
        Node* nxt= head;
        // origanl1 -> copy1 -> original2 ->copy2 ->null
        // add copy nodes next to original nodes
        while(curr){
            nxt = curr->next;
            node* copy = new Node(curr->val);
            curr->next = copy;
            copy ->next = nxt;
            curr= nxt;
        }
        // add random ptr also to the copy nodes 
        curr= head;
        // o1->c1->o2->c2->o3->c3->null
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
                // copy-> random = original -> random ->next (copy of original)
            }
            curr= curr->next->next; // move ptr to next copy
        }

        // restore the original list  , and extract the copy list 
        Node* outhead = new Node(-1);
        Node* out = outhead;

        curr= head;

        while(curr){
            out->next = curr->next; // pointing to copy node
            out = out->next;

            curr->next= curr->next->next; // restoring the link to orinal to next original
            curr= curr->next;
        }

        return outhead->next;
    }
};




// @lc code=end

int main(){

    return 0;
}
