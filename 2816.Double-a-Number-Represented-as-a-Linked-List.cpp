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
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}


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

int main(){

    return 0;
}