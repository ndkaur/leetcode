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






