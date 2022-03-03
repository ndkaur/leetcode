/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

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
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node* flattern_rec(*Node head){
        Node *curr=head;
        Node *tail=head;
        while(curr){
            Node *child=curr->child;
            Node *next=curr->next;

            if(child){
                Node *_tail = flattern_rec(child);
                _tail->next=next;

                if(next)
                    next->prev=_tail;
                
                curr->next=child;
                child->prev=curr;

                curr->child=nullptr;
                curr=_tail;
            }
            else 
                curr=next;
            if(curr)
                tail=curr;
        }
        return tail;
    }
public:
    Node* flatten(Node* head) {
        if(head)
            flattern_rec(head);
        return head;
    }
};


class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return head;
        Node* temp= head;
        Node* childNext =NULL;
        Node* tempChild = NULL;
        while(temp){
            if(temp->child){
                childNext = temp->next;
                temp->next= temp->child;
                temp->child->prev=temp;
                tempChild= temp->child; 
                while(tempChild->next){
                    tempChild= tempChild->next;
                }
                tempChild->next= childNext;
                if(childNext)
                    childNext->prev= tempChild;
                temp->child= NULL;
            }
            temp = temp->next;
        }
        return head;
    }
};
// @lc code=end

int main(){

    return 0;
}