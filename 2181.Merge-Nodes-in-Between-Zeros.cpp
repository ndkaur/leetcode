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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr= dummy;
        ListNode* temp= head;
        temp= temp->next;
        while(temp){
            while(temp->val!=0){
                sum+= temp->val;
                temp= temp->next;
            }
            curr->next = new ListNode(sum);
            curr= curr->next;
            temp= temp->next;
            sum=0;
        }
        return dummy->next;
    }
};

// iterative O(n) O(1)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy= new ListNode(-1);
        //  some ptr to store first position of curr
        ListNode* curr= dummy;
        //  tmp = head->next beacuse head is 0 we dont want to include it 
        ListNode* temp= head->next;
        // temp = temp->next;
        while(temp){
            int sum=0; // every time new sum is formed 
            while(temp->val!=0){
                sum+= temp->val;
                temp= temp->next;
            } // temp will be at the 0 val 
            //add the new formed sum as a node to the dummy list 
            curr->next= new ListNode(sum);
            curr= curr->next;
            // move temp to next non 0 value 
            temp= temp->next;
        }
        return dummy->next;
    }
};

//  recursion  O(n) O(1)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(head->next==NULL)
            return NULL;
        ListNode* temp= head->next;
        int sum=0;
        while(temp->val!=0){
            sum+= temp->val;
            temp= temp->next;
        }
        head->next->val= sum;
        head->next->next= mergeNodes(temp);
        return head->next;
    }
};

int main(){

    return 0;
}