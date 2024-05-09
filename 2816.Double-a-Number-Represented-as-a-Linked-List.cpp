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
// #include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}


//  * Definition for singly-linked list.
 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(!head)
            return head;
        if(head->val==0 && !head->next)
            return head;
        // 189 sum calcutation start form back so reverse
        ListNode* head2 = reverse(head);
        //981
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry =0;
        while(head2 || carry){
            int sum =0;
            if(head2){ // 981 +981 = 9*2
                sum += (head2->val)*2;
                head2 = head2->next;
            }
            sum+=carry;
            carry = sum/10;
            ListNode* curr = new ListNode(sum%10);
            temp->next = curr;
            temp = temp->next;
        }
        return reverse(dummy->next);
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev =NULL;
        ListNode* curr = head;
        ListNode* nxt;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev= curr;
            curr= nxt;
        }
        return prev;
    }
};

// using stack 
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(!head)
            return head;
        if(head->val==0 && !head->next)
            return head;
        stack<int> stk;
        int val = 0;
        while(head){
            stk.push(head->val);
            head= head->next;
        }
        ListNode* dummy = NULL;

        while(stk.size() || val!=0){
            // Create a new ListNode with value 0 and the previous tail as its next node
            // dummy = 8 , now new dummy = new->8
            dummy = new ListNode(0, dummy);
            if(stk.size()){
                val += stk.top()*2;
                stk.pop();
            }
            dummy->val = (val%10);
            val = val/10;
        }
        return dummy;
    }
};

// tle
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr= nxt;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        if(!head)
            return head;
        if(head->val==0 || !head->next)
            return head;
        int val = 0;
        while(head){
            val = val*10+head->val;
            head= head->next;
        }
        cout<<val<<endl;
        val = val*2;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        // 378 
        while(val){
            int rem = val%10; 
            curr->next = new ListNode(rem);
            curr = curr->next;
            val = val/10;
        }
        return reverse(dummy->next);
    }
};


int main(){
    Solution sol;
    ListNode* head = {1};
    ListNode* ans= sol.doubleIt(head);
    
    return 0;
}