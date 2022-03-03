/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 */
#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }
        int sum=0;
        ListNode *head=NULL;
        while(!s1.empty() || !s2.empty() || sum ) {
            if(!s1.empty()){
                sum=sum+s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum=sum+s2.top();
                s2.pop();
            }
            ListNode *helpnode = new ListNode(sum%10);
            helpnode->next=head;
            head=helpnode;

            sum=sum/10;
        }
        return head; 
    }
};

//  help= 7 
// help -> next= head    head= null   so  it becomes  help= 7->next= head -----> 7->null
// head=  help    when new node comes we add it to help ->next which is head 
//  so new node is getting added in front of previous head   8->7 

class Solution {
public:
    ListNode* reverseL(ListNode* head){
        ListNode* curr= head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* temp= curr->next;
            curr->next= prev;
            prev= curr;
            curr= temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1= reverseL(l1);
        l2= reverseL(l2);
        int carry=0;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(l1 || l2 || carry){
            int sum=0;
            if(l1){
                sum+= l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+= l2->val;
                l2= l2->next;
            }
            sum+= carry;
            carry = sum/10;
            ListNode* node= new ListNode(sum%10);
            temp->next = node;
            temp= temp->next;
        }
        return reverseL(dummy->next);
    }
};

int main(){
    Solution sol;
    vector<int> a={7,2,4,3};
    vector<int> b={5,6,4};
    ListNode *l1= createList(a);
    ListNode *l2=createList(b);
    ListNode *head=sol.addTwoNumbers(l2,l2);
    printList(head);
    return 0;

}






